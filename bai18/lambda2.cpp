//vd2 : muốn dùng nhiều biến mà không khai báo trong lambda thì thêm dấu = ngay danh sách biến
#include<iostream>
using namespace std;
// nghĩa là khi dùng dấu = thì ta có thể thêm vào các biến đã được khai báo từ trước
int main(int argc, char const *argv[])
{
    int c=7;
    int d=3;
    int f=8;
    auto test =[=](int a, int b)->int{
        return a+b+c+f; 
    };
    cout<<test(7,9)<<endl; 
    return 0;
}
