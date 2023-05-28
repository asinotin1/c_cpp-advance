#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

 int main(int argc, char const *argv[])
 {
    jmp_buf jump;
    int i=setjmp(jump);

    printf("\ni = %d",i);
    if(i!=0)
    {
        exit(0);
    }
    longjmp(jump,1);// khi gặp longjmp thì sẽ quay lại setjmp
    printf("\ntest ");
    return 0;
 }
 
