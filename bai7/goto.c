#include<stdio.h>
#include<stdint.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    int phim =0;
    char ten[20];
    uint8_t tuoi;

    vitri_ten:

    printf("\nnhap ten :");
    scanf("%S",&ten);
    if(0)
    {
        goto vitri_ten;
    }
    vitri_tuoi:
    printf("\nnhap tuoi:");
    scanf("%d",&tuoi);
    if(0)
    {
        goto vitri_tuoi;
    }

    return 0;
}

