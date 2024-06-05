//AddressSanitizer is not available for Clang compiler.  
//https://github.com/arsenm/sanitizers-cmake
//https://learn.microsoft.com/ru-ru/cpp/build/reference/fsanitize?view=msvc-170
//https://habr.com/ru/articles/341694/ - UBSan, MSan и TSan
//UndefinedBehaviorSanitizer?
int UB()
{
    int i = 10;
    i = i++ + ++i;
    return i;
}

int main(int argc, char **argv)
{
	if(!UB())
		return 1;

    //Run-Time Check Failure #3 - The variable 'b' is being used without being initialized.
    if (1) {bool b; if (b) { b = !b; }}

    //Ошибка санитайзера адресов: Переполнение буфера стека
    if (1) {int a[10] = { 0 }; a[10] = 1;}

    //Ошибка санитайзера адресов: Использование больше не выделенной памяти
    if (1)
    {
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
    
    //Ошибка санитайзера адресов: Отмена выделения освобожденной памяти
    if (1) { int* array = new int[argc + 1]; delete[] array;delete[] array;}

    //leakage?
    if (1){ new int[argc + 1];}

    return 0;
}
