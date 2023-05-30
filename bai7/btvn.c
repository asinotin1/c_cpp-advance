#include<stdio.h>
#include<string.h>
void nhapten()
{
    
    char ten[20];
    int linh_canh=0;
     vi_tri_ten:
    printf("\nnhap ten:");
    fgets(ten,sizeof(ten),stdin);
     for(int i=0;i<strlen(ten);i++)
     {
        if(ten[i]<65||ten[i]>90)
        {
            linh_canh=1;
            break;
        }
     }
     if(linh_canh==1)
     {
        printf("\nten ban nhap khong hop le ");
        goto vi_tri_ten;
     }
     printf("ten ban nhap la:");
     puts(ten);
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

