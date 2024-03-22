#include <stdio.h>
#include <memory>

void main() {
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