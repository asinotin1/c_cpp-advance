#include<stdio.h>
#include<stdint.h>
// kích thước của union phụ thuộc vào member lớn nhất
typedef union 
{
    uint16_t var1; //1 byte
    uint32_t var2; //4 byte
    uint64_t var3;// 8 byte

    // uint16_t var1[3];
    // uint32_t var[7]; // 27byte
    // uint64_t var[4]; //32 byte  
    
}typedata;


int main(int argc, char const *argv[])
{
    typedata data;
    printf("size:%d",sizeof(data));
    return 0;
}
