#include<stdio.h>
#include<stdarg.h>
// truyền vào 1 tham số không xác định

void tong(int so_input,...)
{
    int sum=0;
    va_list va;// số hiện ra
    va_start(va,so_input);// số input là số lượng nhập vào 
    for (int i = 0;i<so_input; i++)
    {
        printf("so nhap vao:%d\n", va_arg(va, int));
    }
    va_end(va);// thu hồi bộ nhớ
}
int main()
{
    tong(4,3,2,5,6,8);
    return 0;
}
