#include<iostream>
#include<cmath>
using namespace std;

class diem
{
    private:
    double x;
    double y;
    public:
    double getX()
    {
    	return this->x;
    }
    void setX(double x)
    {
    	this->x = x;
    }

    double getY()
    {
    	return this->y;
    }
    void setY(double y)
    {
    	this->y = y;
    }
    double khoangcanhdiem(diem Z)
    {
        double xz=x-Z.x;
        double yz=y-Z.y;
        return sqrt(xz*xz+yz*yz);
    }
    double dientichtamgiac(diem A,diem B)
    {
        double dodai1=khoangcanhdiem(A);
        double dodai2=khoangcanhdiem(B);
        double dodai3=A.khoangcanhdiem(B);// độ dài từ A đến B
        double P=(dodai1+dodai2+dodai3)/2;
        return sqrt(P*(P-dodai1)*(P-dodai2)*(P-dodai3));

    }

};

int main(int argc, char const *argv[])
{
    diem L1,L2,L3;
    L1.setX(3.2);
    L1.setY(3.5);
    L2.setX(2.6);
    L2.setY(3.6);
    L3.setX(8.9);
    L3.setY(7.6);
    double H =L1.khoangcanhdiem(L2);
    double H1=L1.dientichtamgiac(L2,L3);
    cout<<" khoang cach giua 2 diem la : "<<H<<endl;    
    cout<<"dien tich tam giac la : "<<H1<<endl;
    return 0;
}
