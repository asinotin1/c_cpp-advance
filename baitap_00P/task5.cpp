#include<iostream>
#include<string>

using namespace std;
class people
{
    private:
    string name;
    int year;
    string address;
    public:
    people(string name, int year, string addres)
    {
        this->name=name;
        this->year=year;
        this->address=address;
    }
    void xuathongtin()
    {
        cout<<"name:"<<name<<endl;
        cout<<"year"<<year<<endl;
        cout<<"address"<<address<<endl;
    }
    int caculatorAge(int s)
    {

        int age=s-year;
        return age;
    }

};

int main(int argc, char const *argv[])
{
    people a("luan",2001,"tp hcm");
    a.xuathongtin();
    double age=a.caculatorAge(2023);
    cout<<"so tuoi la: "<<age<<endl;
    re
