#include<stdio.h>
#include<stdint.h>
// test là không đc khai báo kiểu dữ liệu trong cục bộ
// chỉ được đọc không được sửa đổi

const uint8_t temp=15;// biến này đc lưu ở test nên chỉ đọc không sửa được
 
int main(int argc, char const *argv[])
{
    temp=20;
    printf("temp=%d",temp);
    return 0;
}
