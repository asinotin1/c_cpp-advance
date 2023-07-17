/* sự kết hợp giữa struct và union*/
#include<stdint.h>
#include<stdio.h>
 typedef struct 
 {
    char ten[30];
    uint8_t leve;   
    
 }giangvien;


 typedef struct 
 {
    char ten[30];
    uint8_t class;
 }sinhvien;

typedef union 
{
    giangvien gv;
    sinhvien sv;
}infor;
/* trong ví dụ trên thì union sẽ cấp phát cho thằng có bộ nhớ lớn nhất
-vì cùng khai báo 1 kiểu nên sẽ có số byte bằng nhau
*/
  
int main(int argc, char const *argv[])
{
    infor Luan;
    printf("nhap ten sinh vien :");
    fgets(Luan.sv.ten, 30, stdin);
    printf("ten la :");
    printf("lop sinh vien  :");
    scanf("%d",&Luan.sv.class);
    /* code */
    return 0;
}
