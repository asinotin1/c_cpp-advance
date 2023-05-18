#include<stdio.h>
#include<stdint.h>
void count()
// biến này sẽ chỉ chạy trong hàm này và khi hết nó sẽ thu hồi vùng nhớ
{
    uint8_t temp=0;// biến cục bộ 
    printf("temp=%d\n",temp);
    temp++;
}
void count2()
{
    // biến static nó sẽ chạy hết chương trình thì mới bị thu hồi vùng nhớ
    static uint8_t temp=0;// 0xa1
    printf("temp=%d\n",temp);
    temp++;
}
int main()
{
    /* code*/
    count();//temp//0x01
    count();
    count();


    count2();
    count2();
    count2();
    return 0;
}
