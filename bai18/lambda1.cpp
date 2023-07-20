/*Lambda là một tính năng mới được giới thiệu trong tiêu chuẩn C++11, 
cho phép bạn định nghĩa một hàm vô danh trực tiếp trong một biểu thức hoặc một hàm khác.
 Lambda cung cấp một cách tiện lợi để tạo ra các hàm ngắn gọn và dễ đọc hơn, 
 giúp tăng cường tính linh hoạt và sức mạnh của C++.
*/

// cú pháp :[danh sách biến](paramas-list)->kiểu trả về {nội dung chương trình };
// vd1:
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a=7;
    int b=3;
    auto test =[](int a, int b)->int{
        return a+b;
    };
    cout<<test(7,9)<<endl; // việc dùng lambda giống như việc dùng hàm nhưng dùng lambda thì tiện và tối ưu bộ nhớ hơn
    return 0;
}
