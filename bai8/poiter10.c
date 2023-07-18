// cấp phát vùng nhớ động cho con trỏ
#include<stdio.h>
#include<stdlib.h>
void capphatvungnho(int **pt)
{
  *pt=calloc(10,sizeof(int));
}
int main()
{
  int *pt=NULL;
  capphatvungnho(&pt);
  pt[0]=1;
  printf("%d",&pt[0]);
  return 0;
}
