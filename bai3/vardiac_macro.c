/*varidiac macro giúp tiện hon vardiac và có thể biến đổi và in ra các ký tự mà variac không làm đc*/
#include<stdio.h>
#include<stdlib.h>
#define LOG(...)   printf(__VA_ARGS__)
int main(int argc, char const *argv[])
{
    LOG("LUAN\n");
    LOG("%d+%d=%d",1,2,3);
    
    return 0;
}
