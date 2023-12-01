set n=100000

set NUMBER_OF_PROCESSORS=100
bin\Release\openmp_test.exe

set NUMBER_OF_PROCESSORS=1
bin\Release\openmp_test.exe