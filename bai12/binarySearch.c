#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50
#define MIN_VALUE 1
#define MAX_VALUE 10

void swap(uint8_t *a, uint8_t *b)
{
    uint8_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void CreateArry(uint8_t arr[])
{
    uint8_t i;
    // khởi tạo mảng cho hàm rand
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    }
}

uint8_t binarysearch(uint8_t arr[], uint8_t x)
{

    uint8_t left = 0;
    uint8_t rigth = SIZE - 1;
    while (left <= rigth)
    {
        uint8_t mid = (left + rigth) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            rigth = mid - 1; // chuyển right về dưới mid để giảm vòng lặp
        }
        else
        {
            left = mid + 1; // chuyển left lên trên mid  để giảm vòng lặp
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    uint8_t arr[SIZE];

    // khởi tạo mảng với các giá trị ngẫu nhiên
    CreateArry(arr);

    // in ra mảng
    printf("\n mang ngau nhien:");
    for (uint8_t i = 0; i < SIZE; i++)
    {
        printf("\t%d", arr[i]);
    }

    // tìm kiếm phần tử x trong mảng
    uint8_t x = 3;
    uint8_t vitri = binarysearch(arr, x);
    if (vitri == x)
    {
        printf("\n Khong tim thay phan tu %d trong mang.", x);
    }
    else
    {
        printf("\n Tim thay phan tu %d tai vi tri %d trong mang.", x, vitri);
    }

    return 0;
}
