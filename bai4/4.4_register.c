#include <stdio.h>
#include <stdint.h>
#include <time.h>



int main(int argc, char const *argv[])
{
   clock_t start, end;

  register uint32_t i;// nếu k có register thì tốc độ xử lý của ram rất là chậm

   start = clock();  //1s

   for ( i = 0; i < 0xFFFFFFFF; i++); //3s

   end = clock();    //4s

   printf("time: %f\n", (double)(end - start)/CLOCKS_PER_SEC);
   

    return 0;
}
