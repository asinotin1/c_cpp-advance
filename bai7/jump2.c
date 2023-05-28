#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

jmp_buf buf;
int check_value=0;

#define try if(check_value =setjmp(buf)==0)

#define catch(num) else if(check_value==num)

#define THROW(num) longjmp(buf,num)

double thuong(int a,int b)
{
    if(b==0)
    {
        THROW(0);
    }
    if(b==5)
    {
        THROW(2);
    }
    return (double)a/b;
}


int main(int argc, char const *argv[])
{
    double kq;
    try
    {
        kq=thuong(12,5);
        printf("kq=%f",kq);
    }catch(1)
    {
        printf("Error mau bang 0");
    }catch(2)
    {
        printf("ERROR mau bang 5");
    }
    
    return 0;
}
