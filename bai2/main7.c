#include <stdio.h>

#define stm32 1
#define stm8 2
#define chip 2
#undef chip 2
#ifndef chip
#define chip 1
#endif


int main()
{

    #if(chip == stm32)
    printf("hi");
    #elif(chip  == stm8)
    printf("hello");
    #else
    printf("\nthe fuck");
    #endif
    printf("\nket thuc");
    
}
