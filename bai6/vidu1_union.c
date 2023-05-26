#include<stdio.h>
#include<stdint.h>
#include<string.h>

typedef union
{
    uint8_t var1; // kiểu dữ liệu char
    uint16_t var2; // kiểu dữ liệu long 
    uint64_t var3;

}typedata;


int main(int argc, char const *argv[])  
{
    typedata data;
    data.var2=1234;
    printf("var1=%d, var3=%d\n",data.var1,data.var3);
    return 0;
}
