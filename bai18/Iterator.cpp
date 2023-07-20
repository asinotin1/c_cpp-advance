/*Một Iterator là một đối tượng có thể đi qua (iterate over) một container class mà không cần biết trật tự các phần tử bên trong mảng. 
Iterator còn là một cách để truy cập dữ liệu bên trong các container.*/
#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int main(int argc, char const *argv[])
{
    list <int> array;
    array.push_back(3);
    array.push_back(4); 
    array.push_back(6);
    array.push_back(2);
    list <int> :: iterator it; // it là viết tắt của iterator và it là 1 con trỏ
    for(it = array.begin();  it!= array.end(); ++it )
    {
        if(*it==3)
        {
            array.erase(it);
            break;
        }
    }
    for(it = array.begin(); it!= array.end(); ++it )
    {
        cout<< *it<<endl;
    }
    return 0;
}
