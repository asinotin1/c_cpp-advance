#include<iostream>
#include<cmath>
#include<string>
using namespace std;
class car
{
    private:
    string color;
    string machine;
    unsigned int kilomet;
    public:
    car(string color,string machine,unsigned int kilomet)
    {
        this->color=color;
        this->machine=machine;
        this->kilomet=kilomet;

    }
    double maintenanceCost()
    {
        if(kilomet<4000)
        {
            return 100;
        }
        else if (kilomet<10000)
        {
            return 500;
        }
        else
        {
            return 700;
        }
        
    }
    void checkKM()
    {
        cout<<"so km da di la:"<<kilomet<<endl;
    }
    void thongtin()
    {
        cout<<" mau sac : "<<color<<endl;
        cout<<" dong co la :"<< machine<<endl;
        cout<<"so km la :"<<kilomet<<endl;
    }

};

int main(int argc, char const *argv[])
{
    car s1("do","vf76",30000);
    s1.thongtin();
    s1.checkKM();
    double tinhtien=s1.maintenanceCost();
    cout<<"so tien bao duong la :"<<tinhtien<<endl;

    return 0;
}
