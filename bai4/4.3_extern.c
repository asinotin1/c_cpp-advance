#include<stdio.h>
#include<stdint.h>

extern void count();// liên kết 2 file c với nhau là 4.2 với 4.3

int main()
{
    /* code*/
    count();

    count();
    return 0;
}
