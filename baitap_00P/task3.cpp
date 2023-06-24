#include<iostream>
#include<cmath>
using namespace std;

class hinhtron
{
    private:
    double R;
    public:
    double getR()
    {
	return this->R;
    }
    void setR(double R)
   {
	this->R = R;
   }
   double chuvi()
   {
    double c;
    c=R*R*3.14;
    return c;
   }
   double dientich()
   {
    double s;
    s=R*2*3.14;
    return s;
   }

};
int main(int argc, char const *argv[])
{
    hinhtron a;
    a.setR(5);
    double C=a.chuvi();
    double S=a.dientich();  
    cout<<"chu vi: "<<C<<endl;
    cout<<" dien tich: "<<S<<endl;
    
    return 0;
}
