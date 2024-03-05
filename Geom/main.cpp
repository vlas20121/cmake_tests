#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>

/// <summary>
/// basec numerical
/// </summary>
namespace BaseNumerical {
    template<class NUMBER>
    bool equ_approx(NUMBER v0, NUMBER v1)
    {
        auto eps=std::numeric_limits<NUMBER>::epsilon();
        return std::abs(v0 - v1) < eps * 1000000;
    }
}

/// <summary>
/// generic geometry
/// </summary>
namespace BaseGeometry {
    using namespace BaseNumerical;

    template<class T, int n>
    using vec = std::array<T, n>;

    template<class VEC>
    VEC operator+(const VEC& v1, const VEC& v2)
    {
        VEC ret;
        for (int i = 0; i < v1.size(); i++)
            ret[i] = v1[i] + v2[i];
        return ret;
    }
    template<class VEC>
    VEC operator-(const VEC& v1, const VEC& v2)
    {
        VEC ret;
        for (int i = 0; i < v1.size(); i++)
            ret[i] = v1[i] - v2[i];
        return ret;
    }
    template<class VEC>
    VEC operator*(const VEC& v1, typename VEC::value_type v2)
    {
        VEC ret;
        for (int i = 0; i < v1.size(); i++)
            ret[i] = v1[i] * v2;
        return ret;
    }
    template<class VEC>
    VEC operator/(const VEC& v1, typename VEC::value_type v2)
    {
        //assert();
        return v1*(1./v2);
    }

    template<class VEC>
    typename VEC::value_type dot(const VEC& v1, const VEC& v2)
    {
        VEC::value_type ret = double();
        for (int i = 0; i < v1.size(); i++)
            ret += v1[i] * v2[i];
        return ret;
    }

    template<class VEC>
    typename VEC::value_type abs2(const VEC& v)
    {
        return dot(v, v);
    }

    template<class VEC>
    typename VEC::value_type abs(const VEC& v)
    {
        return std::sqrt(abs2(v));
    }
    template<class VEC,class STREAM>
    void to_stream(STREAM& stream, const VEC& v)
    {
        stream << "vec" << v.size() << "{";
        for (int i = 0; i < v.size(); i++)
        {
            stream << v[i];
            if(i<v.size()-1)
                stream << ",";
        }
        stream << "}";
    }
};

/// <summary>
/// some 2d/3d geometry
/// </summary>
namespace Geometry{
    using namespace BaseGeometry;
    using vec2 = vec<double, 2>;
    using vec3 = vec<double, 3>;
    using vec3imm = vec<const double, 3>;

    using LineSegment = std::array<vec3, 2>;
    double Distance(const LineSegment& p, const vec3& pt)
    {
        //todo
        return double();
    }

	using PolyLine=std::vector<vec3>;///полилиния задается как набор последовательно соединенных точек
	double Distance(const PolyLine& p, const vec3& pt)
	{
        //todo
        return double();
	}

    /// <summary>
    /// circle parameters
    /// </summary>
    struct circle
    {
        vec2 center;
        double radius;
    };

    /// <summary>
    /// Rotate vector by angle 
    /// </summary>
    /// <param name="p">vector for rotae</param>
    /// <param name="rot">rotate direction; rot=vec2{sin(angle),cos(angle)}</param>
    /// <returns>rotated vector</returns>
    vec2 Rotate(const vec2& p, const vec2& rot)
    {
        return vec2{
            p[0] * rot[1] - p[1] * rot[0],
            p[0] * rot[0] + p[1] * rot[1]
        };
    }
    /// <summary>
    /// return tangent point's from point to circle
    /// </summary>
    /// <param name="circ">circe</param>
    /// <param name="p">from point</param>
    /// <param name="second">1st or 2st tangent point</param>
    /// <returns>tangent point</returns>
    vec2 circle_tangent_point(const circle& circ, const vec2& p, bool second=false)
    {
        assert(circ.radius > 0);
        vec2 l = circ.center - p;
        double L = abs(l);
        assert(circ.radius<=L);
        double _sin = circ.radius / L;
        double _cos = std::sqrt(1 - _sin * _sin);
        if (second)
            _sin = -_sin;
        vec2 t = p + Rotate(l, vec2{ _sin, _cos }) * _cos;
        return t;
    }
};

// immutable:

/// <summary>
/// testing geometry immutability
/// </summary>
void immutable()
{
    using namespace Geometry;
    [[maybe_unused]] vec3imm v1{ 1,2,3 };
    vec3imm v2{ 3,2,1 };
    //auto v = v1+v2;
}

using namespace Geometry;

void circle_tangent_point_check(const circle& circ, const vec2& p, const vec2& t)
{
    double _dot = dot(t - circ.center, t - p);
    assert(equ_approx(_dot, 0.));
}

void circle_tangent_point_test(const circle& circ, const vec2& p)
{
    vec2 t0 = circle_tangent_point(circ, p);
    vec2 t1 = circle_tangent_point(circ, p, true);

    circle_tangent_point_check(circ, p, t0);
    circle_tangent_point_check(circ, p, t1);

    std::cout << "circle_tangent_point_test:";
    to_stream(std::cout, t0); std::cout << ","; to_stream(std::cout, t1); std::cout << "\n";
}

void circle_tangent_point_test()
{
    circle_tangent_point_test(circle{ { 0,0 }, 1 }, vec2{ 100, 0 });
    circle_tangent_point_test(circle{ { 0,0 }, 1 }, vec2{ 2, 0 });
    circle_tangent_point_test(circle{ { 0,0 }, 1 }, vec2{ 1.01, 0 });
    circle_tangent_point_test(circle{ { 0,0 }, 1 }, vec2{ 1.0001, 0 });
}

void main()
{
    [[maybe_unused]] auto v2def = vec2();
    [[maybe_unused]] vec2 vt_c;
    [[maybe_unused]] vec2 vt_c1({1., 2.});

    auto v1 = vec3{ 1,2,3 } + vec3{ 3,2,1 };
    auto v2 = vec3{ 1,2,3 } *2.;

    PolyLine pl = {
        vec3{0,0,0},
        vec3{0,1,0},
        vec3{1,1,0},
        vec3{1,0,0},
        vec3{0,0,0}
    };
    LineSegment ls{ pl[0] ,pl[1] };
    auto bls0 = Distance(ls, pl[0]);
    auto b0 = Distance(pl, pl[0]);
    auto b1 = Distance(pl, vec3{ 0.5,0.5,0.5 });
    circle_tangent_point_test();
}
