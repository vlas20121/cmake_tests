//likely PVS-Studio bug

int main()
{
    enum Result { Result1 = 1, Result2 = 2 };
    Result result = Result1;
    switch (result)
    {
    case/* */Result1:   //V729 Function body contains the 'caseResult1' label that is not used by any 'goto' statements. D:\GitHub\TestGroup\cmake_tests\check_pvs_commenting\main.cpp 11
        break;
    }
}

