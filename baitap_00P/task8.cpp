#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Tkbank
{
    private:
    unsigned int AccountNumber;
    string name;
    unsigned int surplus;
    public:
    Tkbank(unsigned int AccountNumber,string namne, unsigned int surplus)
    {
        this->AccountNumber=AccountNumber;
        this->name=name;
        this->surplus=surplus;
    }
    bool checkMoney()
    {
        if(surplus>50)
        {
            return true;
        }
        else
        {
            return false;
            exit(1);
        }
    }
     void  TakeMoney(unsigned int s)
    {
        
        if(checkMoney())
        {
            surplus=surplus-s;

        }
    }
    void payment(unsigned int k)
    {
        surplus=surplus+k;
    }
    void inthongtin()
    {
        cout<<"so tai khoan la: "<<AccountNumber<<endl;
        cout<<"ten tai khoan la: "<<name<<endl;
        cout<<" so du la :"<<surplus<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Tkbank s1(123323," tran quang luan",10000);
    s1.TakeMoney(400);
    s1.inthongtin();
    s1.payment(600);
    s1.inthongtin();
    return 0;
}
