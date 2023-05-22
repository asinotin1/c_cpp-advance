#include<stdio.h>
#include<stdint.h>

int tong(int a, int b)
{
    int c=a+b;
    printf("dia chi a =%p\n",&a);
    return c;

}
int main(int argc, char const *argv[])
{
    printf("tong=%d\n",tong(3,5));//int a=3 //0x01
                                  //int b=5 //0x02
                                  //int c=8 //0x03 




    printf("tong=%d\n",tong(4,7));//int a=4//0xc1;
                                  //int b=5//0xc2
                                  //int c=11//0xc3

    return 0;
}
