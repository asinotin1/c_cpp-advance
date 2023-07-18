/*bit filed : giúp chúng ta tiết kiệm số byte trong 1 struct */
// ví dụ trong struct test 1 : ta chỉ tốn 4 bit trong 1 struct vì nó lấy kiểu dữ liệu dầu tiên của biến trong struct
// bit filed : thường rất ít khi sử dụng và chỉ dùng trong các cờ trong class và không quá quan trọng
#include <stdio.h>
 
// A structure without forced alignment
struct test1 {
    unsigned int x : 5;
    unsigned int y : 8;
};
 
// A structure with forced alignment
struct test2 {
    unsigned int x : 5;
    unsigned int : 0;
    unsigned int y : 8;
};
 
int main()
{
    printf("Size of test1 is %lu bytes\n",
           sizeof(struct test1));
    printf("Size of test2 is %lu bytes\n",
           sizeof(struct test2));
    return 0;
}
