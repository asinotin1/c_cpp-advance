// Online C compiler to run C program online
#include <stdio.h>
typedef void(*BARKFN)();

typedef struct
{
    BARKFN bark;
    
}Dog;

void husky()
{
    printf("\ngau gau");
}
void choco()
{
    printf("\nang ang ....");
}

Dog cho1 ={husky};
Dog cho2 = {choco};


int main() {
cho1.bark();
cho2.bark();

    return 0;
}
