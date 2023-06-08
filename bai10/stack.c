#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdlib.h>

int8_t i = -1; // chạy từ vị trí 0

#define size 5
//IsEmpty: Kiểm tra ngăn xếp trống hay không. Ngăn xếp trống là ngăn xếp không có phần tử nào.

bool isEmpty()
{
    if(i == -1)
    {
        return true;
    }
    else
    {
        return false;
    }

}
//IsFull: Kiểm tra ngăn xếp đã đầy hay chưa. Thao tác này không phải lúc nào cũng có.

bool isFull()
{
    if(i == size-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//Push: Thêm một phần tử vào đỉnh của ngăn xếp, số phần tử của ngăn xếp tăng lên 1.

void push(uint8_t stack[],uint8_t value)
{
    if(isFull())
    {
        printf("\nstack is full");
    }
    else
    {
        // tăng giá trị chạy lên 1 đơn vị
        stack[++i]=value;// cho giá trị mới thêm bằng = value
    }

}

//Pop: Xóa bỏ phần tử đầu tiên ở đỉnh của ngăn xếp, số phần tử của ngăn xếp giảm đi 1.

void pop(uint8_t stack[])
{
    if(isEmpty())
    {
        printf("\n stack is empty");
    }
    else
    {
        i--;
    }
}

//Top: Lấy giá trị của phần tử đầu tiên ở đỉnh của ngăn xếp, số phần tử của ngănxếp không thay đổi.
uint8_t top(const uint8_t stack[])
{
    return stack[i];

}

//Size: Lấy số lượng phần tử stack đang có.
uint8_t SiZE()
{
    return i+1;
}

int main(int argc, char const *argv[])
{
    uint8_t stack[abs(i)];

    push(stack,15);
    push(stack,2);
    push(stack,3);
    push(stack,4);

    pop(stack);
    pop(stack);

    printf("\ntop =%d",top(stack));
    printf("\nSIZE =%d",SiZE());

    return 0;
}
