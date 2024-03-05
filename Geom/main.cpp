#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>

namespace BaseNumerical {
    template<class NUMBER>
    bool equ_approx(NUMBER v0, NUMBER v1)
    {
        auto eps=std::numeric_limits<NUMBER>::epsilon();
        return std::abs(v0 - v1) < eps * 1000000;
    }
}

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
};

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

    struct circle
    {
        vec2 c;
        double r;
    };
    vec2 Rotate(const vec2& p, double _sin, double _cos)
    {
        return vec2{
            p[0] * _cos - p[1] * _sin,
            p[0] * _sin - p[1] * _cos
        };
    }
    vec2 circle_tangent_point(const circle& circ, const vec2& p, bool second=false)
    {
        assert(circ.r > 0);
        vec2 l = circ.c - p;
        double L = abs(l);
        assert(circ.r<=L);
        double _sin = circ.r / L;
        double _cos = std::sqrt(1 - _sin * _sin);
        if (second)
            _sin = -_sin;
        vec2 _l = Rotate(l, _sin, _cos);
        vec2 _t = _l*_cos;
        vec2 t = p+_t;
        return t;
    }
};

// immutable:

void immutable()
{
    using namespace Geometry;
    [[maybe_unused]] vec3imm v1{ 1,2,3 };
    vec3imm v2{ 3,2,1 };
    //auto v = v1+v2;
}

using namespace Geometry;

void circle_tangent_point_test(const circle& circ, const vec2& p)
{
    vec2 t0 = circle_tangent_point(circ, p);
    vec2 t1 = circle_tangent_point(circ, p, true);
    auto dot0 = dot(t0 - circ.c, t0 - p);
    auto dot1 = dot(t1 - circ.c, t1 - p);
    assert(equ_approx(dot0, 0.));
    assert(equ_approx(dot1, 0.));
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
    auto v2def = vec2();
    circle_tangent_point_test();
}
