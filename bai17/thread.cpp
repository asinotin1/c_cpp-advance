/*Thread trong C++ là một đối tượng thực thi độc lập, 
có thể chạy song song với các thread khác. Bằng cách sử dụng thread, 
bạn có thể tận dụng tối đa tài nguyên của hệ thống bằng cách chia các hoạt động phức tạp thành các tác vụ nhỏ hơn và thực hiện chúng song song.*/
#include<iostream>
#include<thread>
#include<string>
#include<unistd.h>

using namespace std;


void foo()
{
  for (int i = 0; i < 10; i++)
  {
    cout << "thread using ham foo  :"<<i<<endl;
    usleep(10000);// delay 1s
    
  }
}
void foo2()
{
    int i =0;
    while (1)
    {
        cout<<"thread using ham foo2 "<<i<<endl;
        usleep(30000); // delay 3s
        i++;
    }
    
}
 
int main(int argc, char const *argv[])
{
    thread th1(foo);
    thread th2(foo2);

     th1.join();// được gọi để đợi cho thread 1 kết thúc trước khi chương trình kết thúc. 
     th2.join();// được gọi để đợi cho thread 2 kết thúc trước khi chương trình kết thúc.
    
    return 0;
}
