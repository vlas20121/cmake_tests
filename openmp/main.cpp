#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
#include <vector>
#include <cmath>

int main1()
{
    int i;
    int threadID = 0;
    #pragma omp parallel for private(i, threadID)
    for(i = 0; i < 16; i++ )
    {
        threadID = omp_get_thread_num();
        #pragma omp critical
        {
            printf("Thread %d reporting\n", threadID);
        }
    }
    return 0;
}

class TimeDuration
{
public:
    static bool timing() { return true; }
	using high_resolution_clock=std::chrono::high_resolution_clock;
	TimeDuration(const std::string& _s)
		:s(_s)
	{
		if(timing())
			start = high_resolution_clock::now();
	}
	~TimeDuration()
	{
		if (timing())
		{
			auto stop = high_resolution_clock::now();
			double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000000.;
			std::cout << std::fixed << std::setprecision(4);
			std::cout << s.c_str() << duration << "\n";
		}
	}
	high_resolution_clock::time_point start;
	const std::string s;
};

static long long getenv_int(const char* section, size_t def=1)
{
    char* s = std::getenv(section);
    if (!s)
        return def;
    return std::stoull(s);
}

static void ConfigureOmp()
{
    int i_max_threads = getenv_int("NUMBER_OF_PROCESSORS");
    i_max_threads = std::min(i_max_threads, omp_get_max_threads());
    std::cout << "omp_set_num_threads(" << i_max_threads << ");\n";
    omp_set_num_threads(i_max_threads);
}

int main() {
    ConfigureOmp();
    long long n=getenv_int("n",1000);
    //double m = 0.1;
    std::cout << "n=" << n << "\n";
    std::vector<double> v(n);
    TimeDuration tm("openmp::NUMBER_OF_PROCESSORS.time=");
#pragma omp parallel for
    for (long long i = 1; i < n; i++)
	for (int j = 1; j < 10000; j++)
        v[i]= std::sin(j*double(i)/n);
    //std::cout << "mul=" << m << "\n";
    return 0;
}

