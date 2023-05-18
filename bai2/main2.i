#include <stdio.h>

#define Max 10

#define tong(a,b) a+b

// trong file i khong co int a = 10

#ifndef Max
int a = 10;
#endif


#ifdef Max
int a = 25;
#endif

int main(){
    //code
    return 0;
}
