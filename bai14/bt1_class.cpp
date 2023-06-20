#include<iostream>
#include<string>
using namespace std;

class student
{
private:
    string ten;
    double toan;
    double ly;
    double hoa;
    double trungbinh;

public:
    student(string ten, double toan, double hoa, double ly);
    string getTen() {
        return this->ten;
    }
    void setTen(string ten) {
        this->ten = ten;
    }

    double getToan() {
        return this->toan;
    }
    void setToan(double toan) {
        this->toan = toan;
    }

    double getLy() {
        return this->ly;
    }
    void setLy(double ly) {
        this->ly = ly;
    }

    double getHoa() {
        return this->hoa;
    }
    void setHoa(double hoa) {
        this->hoa = hoa;
    }

    double getTrungbinh() {
        return this->trungbinh;
    }
    void setTrungbinh() {
     this->trungbinh = (this->getToan() + this->getLy() + this->getHoa()) / 3;
    }
    void xuatthongtin()
    {
        cout << "Thong tin sinh vien: " << endl;
        cout << "Ten: " << getTen() << endl;
        cout << "Diem toan: " << getToan() << endl;
        cout << "Diem hoa: " << getHoa() << endl;
        cout << "Diem ly: " << getLy() << endl;
        cout << "Diem trung binh: " << getTrungbinh() << endl;
    }
};

student::student(string ten, double toan, double hoa, double ly)
{
    this->ten = ten;
    this->toan = toan;
    this->hoa = hoa;
    this->ly = ly;
    setTrungbinh();
}

int main(int argc, char const *argv[])
{
    student s1("Luan", 3.2, 4.5, 2.5);
    s1.xuatthongtin();

    return 0;
}
