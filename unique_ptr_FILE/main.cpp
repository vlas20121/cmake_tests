#include <stdio.h>
#include <memory>

void t() {
    std::unique_ptr<FILE, int(*)(FILE*)> fp(fopen("test.txt", "r"), fclose);
    std::unique_ptr<FILE, int(*)(FILE*)> fp1(fopen("test1.txt", "r"), fclose);

    if( !fp.get() )
	return;
    if( !fp1.get() )
	return;

    if(fp) {
        char buf[4096];
        while(fgets(buf, sizeof(buf), fp.get())) {
            printf("%s", buf);
        }
    }
    if(fp1) {
        char buf[4096];
        while(fgets(buf, sizeof(buf), fp1.get())) {
            printf("%s", buf);
        }
    }

}
void t_2del()
{
    int* pi = new int(0);
    delete pi;
    delete pi;
}

void t_malloc_del()
{
    int* pi = (int*)malloc(sizeof(int));
        delete pi;
    //free(pi);
}

void main() {
    t();
    //t_2del();
    //t_malloc_del();
}