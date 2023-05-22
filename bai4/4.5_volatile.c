#include<stdio.h>
#include<stdint.h>
#include<time.h>
//volatile: đừng tối ưu biến này 
volatile uint8_t a;
volatile int test=15;

int readDatafromUART();

int main()
{
    while (1)// câu lênh while(1) này sẽ là while(true) nó sẽ là vòng lặp vô hạn
    {
        test=readDatafromUART();
        A();
        B();
        C();
    }
    return 0;
}
