#include<stdio.h>
#include<stdint.h>

void swap(uint8_t *a, uint8_t *b)
{
    uint8_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortlist(uint8_t arry[], uint8_t n)
{
    for(uint8_t i = 0; i < n - 1; i++)
    {
        for(uint8_t j =n-1; j>i; j--)
        {
         if(arry[j]<arry[j-1])
         {
            swap(&arry[j],&arry[j-1]);
         }
        }
    }
}
void dem_so_phantu(uint8_t arry[], uint8_t n,uint8_t x)
{
   uint8_t demphantu=0;
   for(uint8_t i=0;i<n;i++)
   {
      if(arry[i]==x)
      {
         demphantu++;
      }
   }
   printf("so phan tu %d xuat hien trong mang la :%d",x,demphantu);
}

void output(uint8_t arry[], uint8_t n)
{
    for(uint8_t i = 0; i < n; i++)
    {
        printf("\narry[%d] = %d", i, arry[i]);
    }
}

int main(int argc, char const *argv[])
{
    uint8_t arry[] = {1, 9, 2, 4, 32, 1, 2, 5, 8};
    uint8_t n = sizeof(arry) / sizeof(arry[0]);

    printf("\nsap xep theo thu tu tang dan:");
    sortlist(arry, n);
    output(arry, n);
    dem_so_phantu(arry,n,1);

    return 0;
}
