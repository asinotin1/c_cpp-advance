#include<stdio.h>
#include<stdint.h>
typedef struct strutct
{
    /* data */
    uint8_t ngay;
    uint32_t thang;
    uint16_t nam;
}typeDate;

void hienthi(typeDate date)
{
    printf("ngay:%d thang:%d nam:%d\n",date.ngay,date.thang,date.nam);
}

int main(int argc, char const *argv[])
{
    typeDate date;
    printf("size:%u byte\n",sizeof(date));// dung %d hay %u deu dc
    return 0;
}
