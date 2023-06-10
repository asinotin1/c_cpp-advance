#include<stdio.h>
#include<string.h>
#include <ctype.h>
void nhapten()
{
     char name[100];
    while (1) {
        printf("Nhap ten cua ban: ");
        scanf("%s", name);
        int valid = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (!isalpha(name[i]) || !islower(name[i])) {
                valid = 0;
                break;
            }
        }
        if (valid==1) {
            printf("Chao mung %s den voi chuong trinh cua chung toi!\n", name);
            break;
        } else {
            printf("Ten cua ban khong hop le. Vui long nhap lai.\n");
        }
    }
}
int nhaptuoi()
{
    int tuoi;
    vi_tri_tuoi:
    printf("\nnhap tuoi:");
    scanf("%d",&tuoi);
    if(tuoi<0 || tuoi>20)
    {
    printf("\ntuoi ban nhap khong dung:");
    goto vi_tri_tuoi;
    }
    return tuoi;
}
int nhaplop()
{
    int lop;
    vi_tri_lop:
    printf("\n nhap lop:");
    scanf("%d",&lop);
    if(lop<0||lop>12)
    {
        printf("\nlop ban vua nhap khong dung:");
        goto vi_tri_lop;
    }
    return lop;
}
float nhapdiemtoan()
{
    float diemtoan;
    vi_tri_diemtoan:
    printf("\nnhap diem toan:");
    scanf("%f",&diemtoan);
    if(diemtoan<0.0 ||diemtoan >10.0)
    {
        printf("\ndiem ban vua nhap khong phu hop");
        goto vi_tri_diemtoan;
    }
    return diemtoan;
}


int main(int argc, char const *argv[])
{
    char ten[200];
    nhapten();
    printf("\ntuoi ban vua nhap la: %d",nhaptuoi());
    printf("\nlop ban vua nhap la: %d",nhaplop());
    printf("\ndiem toan ban vua nhap la: %.1f",nhapdiemtoan());
    return 0;
}

