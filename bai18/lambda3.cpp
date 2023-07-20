// có thể sử dụng vector và lambda vì trong hàm sort của vector có 3 pramas
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> myvector = {1, 3, 5, 2, 6};    
    sort(myvector.begin(), myvector.end(), [](int a, int b) {
        return a < b;
    });
    cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

    return 0;
}
