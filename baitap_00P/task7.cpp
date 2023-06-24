include<iostream>
using namespace std;

class person
{
    private:
    int ngay,thang,nam;
    public:
    person(int ngay,int thang,int nam)
    {
        this->ngay=ngay;
        this->thang=thang;
        this->nam=nam;
    }
    int  caculatorYear(int S)
    { 
         int age = S-nam;
         return age;
    }
    bool checkday(int holiday)
    {
        if(ngay==holiday)
        {
            cout<<"trung ngay"<<endl;
            return true;
        }
        else
        {
            cout<<"khong trung ngay:"<<endl;
            return false;
        }
    }
    void thongtin()
    {
        cout<<"day : "<<ngay<<endl;
        cout<<"month :"<<thang<<endl;
        cout<<"year :"<<nam<<endl;
        checkday(12);
    }
};

int main(int argc, char const *argv[])
{
    person s1(12,3,5);
    s1.thongtin();
    return 0;
}
