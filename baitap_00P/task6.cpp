#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu_so;
    int mau_so;
public:
    PhanSo(int tu = 0, int mau = 1) 
    {
        this->tu_so = tu;
       this-> mau_so = mau;
    }

    void nhap() 
    {
        cout << "Nhap tu so: ";
        cin >> tu_so;
        cout << "Nhap mau so: ";
        cin >> mau_so;
    }

    void xuat() 
    {
        cout << tu_so << "/" << mau_so;
    }

    PhanSo cong(PhanSo ps) 
    {
        PhanSo kq;
        kq.tu_so = tu_so * ps.mau_so + mau_so * ps.tu_so;
        kq.mau_so = mau_so * ps.mau_so;
        return kq;
    }

    PhanSo tru(PhanSo ps) 
    {
        PhanSo kq;
        kq.tu_so = tu_so * ps.mau_so - mau_so * ps.tu_so;
        kq.mau_so = mau_so * ps.mau_so;
        return kq;
    }

    PhanSo nhan(PhanSo ps) 
    {
        PhanSo kq;
        kq.tu_so = tu_so * ps.tu_so;
        kq.mau_so = mau_so * ps.mau_so;
        return kq;
    }

    PhanSo chia(PhanSo ps) 
    {
        PhanSo kq;
        kq.tu_so = tu_so * ps.mau_so;
        kq.mau_so = mau_so * ps.tu_so;
        return kq;
    }
};

int main() {
    PhanSo ps1, ps2, kq;
    cout << "Nhap phan so thu nhat:\n";
    ps1.nhap();
    cout << "Nhap phan so thu hai:\n";
    ps2.nhap();

    // Tinh toan
    kq = ps1.cong(ps2);
    cout << "Tong 2 phan so: ";
    kq.xuat();
    cout << endl;

    kq = ps1.tru(ps2);
    cout << "Hieu 2 phan so: ";
    kq.xuat();
    cout << endl;

    kq = ps1.nhan(ps2);
    cout << "Tich 2 phan so: ";
    kq.xuat();
    cout << endl;

    kq = ps1.chia(ps2);
    cout << "Thuong 2 phan so: ";
    kq.xuat();
    cout << endl;

    return 0;
}
