//https://stackoverflow.com/questions/34813412/how-to-detect-if-building-with-address-sanitizer-when-building-with-gcc-4-8
//__has_feature(address_sanitizer)
//__has_feature(memory_sanitizer)
//__has_feature(thread_sanitizer)
//__has_feature(undefined_behavior_sanitizer)

#include <stdio.h>
#if defined(__has_feature)
# if __has_feature(address_sanitizer)
#   pragma message("We has ASAN!\n")
# else
#   pragma message("We have has_feature, no ASAN!\n")
# endif
#else
#   pragma message("We got nothing!\n")
#endif

#ifdef __SANITIZE_MEMORY__
#pragma message("Memory sanitizer enabled")
#else
#pragma message("Memory sanitizer not enabled")
#endif

#ifdef __SANITIZE_THREAD__
#pragma message("Thread sanitizer enabled")
#else
#pragma message("Thread sanitizer not enabled")
#endif

#ifdef __SANITIZE_ADDRESS__
#pragma message("Address sanitizer enabled")
#else
#pragma message("Address sanitizer not enabled")
#endif

#ifdef __SANITIZE_UNDEFINED__
#pragma message("UB sanitizer enabled")
#else
#pragma message("UB sanitizer not enabled")
#endif

//AddressSanitizer is not available for Clang compiler.  
//https://github.com/arsenm/sanitizers-cmake
//https://learn.microsoft.com/ru-ru/cpp/build/reference/fsanitize?view=msvc-170
//https://habr.com/ru/articles/341694/ - UBSan, MSan и TSan
//UndefinedBehaviorSanitizer?
int UB1()
{
    int i = 10;
    i = i++ + ++i;
    return i;
}

int UB2()
{
    //Run-Time Check Failure #3 - The variable 'b' is being used without being initialized.
    if (0) { bool b; if (b) { b = !b; } }
    return 0;
}

int UB3()
{
    //Ошибка санитайзера адресов: Переполнение буфера стека
    if (1) { int a[10] = { 0 }; a[10] = 1; }
    return 0;
}

int UB4()
{
    //Ошибка санитайзера адресов: Использование больше не выделенной памяти
    if (1)
    {
        int argc = 10;
        new int[argc + 1];
        // Allocate a new array and delete it.
        int* array = new int[argc + 1];
        array[argc] = 0;
        delete[] array;

        /* Access element of the deleted array. This will cause an memory error with
         * address sanitizer.
         */
        return array[argc];
    }
    return 0;
}

int UB5()
{
    //Ошибка санитайзера адресов: Отмена выделения освобожденной памяти
    int argc = 10;
    if (1) { int* array = new int[argc + 1]; delete[] array; delete[] array; }
    return 0;
}

int UB6()
{
    //leakage?
    int argc = 10;
    if (1) { new int[argc + 1]; }
    return 0;
}

int main(int argc, char **argv)
{
    if (!UB1())
        return 1;
    UB2();
    UB3();
    UB4();
    UB5();
    UB6();
    return 0;
}
