#include<stdio.h>
typedef int(*luan)(int);
int  phepnhan(int x)
{
    return x*x;
}

int main()
{
    luan sqrt = phepnhan;
    printf("%d",sqrt(5));
    
}
