#include<stdio.h>
#include<stdint.h>

 int main(int argc, char const *argv[])
 {
    for(int i=0;i<2;i++)
    {
        printf("i=%d",i);
        exit(0);// dừng toàn bộ chương trình

    }
    printf("test:");
    return 0;
}
