#include<iostream>
#include<cmath>
using namespace std;

class HCN
{
    private:

    double dai;
    double rong;

    public:

    double getDai()
    {
	return this->dai;
    }
    void setDai(double dai) 
    {
	this->dai = dai;
    }
    double getRong()
    {
      return this->rong;
    }
    void setRong(double rong)
    {
    	this->rong = rong;
    }
    bool hinhvuong()
    {
        if(getDai()==getRong())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    double chuvi()
    {
        double p;
        p=2*(getDai()+getRong());
        return p;

    }
    double dientich()
    {
        double s;
        s=getDai()*getRong();
        return s;
    }
    double duongcheo()
    {
        double cheo;
        if(hinhvuong() == 1)
        {
            cheo=getDai()*sqrt(2);
            return cheo;
        }
        else
        {
            cheo=sqrt((dai*dai)+(rong*rong));
            return cheo;
        }
    }
};

int main(int argc, char const *argv[])
{
    HCN a;
    a.setDai(5);
    a.setRong(5);
    double x=a.chuvi();
    double y=a.dientich();
    a.duongcheo();
    cout<<"chu vi la:"<<x<<endl;
    cout<<"dien tich la: "<<y<<endl;
    cout<<"duong cheo la :"<<a.duongcheo()<<endl;

    
    /* code */
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

class HCN
{
    private:

    double dai;
    double rong;

    public:

    double getDai()
    {
	return this->dai;
    }
    void setDai(double dai) 
    {
	this->dai = dai;
    }
    double getRong()
    {
      return this->rong;
    }
    void setRong(double rong)
    {
    	this->rong = rong;
    }
    bool hinhvuong()
    {
        if(getDai()==getRong())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    double chuvi()
    {
        double p;
        p=2*(getDai()+getRong());
        return p;

    }
    double dientich()
    {
        double s;
        s=getDai()*getRong();
        return s;
    }
    double duongcheo()
    {
        double cheo;
        if(hinhvuong() == 1)
        {
            cheo=getDai()*sqrt(2);
            return cheo;
        }
        else
        {
            cheo=sqrt((dai*dai)+(rong*rong));
            return cheo;
        }
    }
};

int main(int argc, char const *argv[])
{
    HCN a;
    a.setDai(5);
    a.setRong(5);
    double x=a.chuvi();
    double y=a.dientich();
    a.duongcheo();
    cout<<"chu vi la:"<<x<<endl;
    cout<<"dien tich la: "<<y<<endl;
    cout<<"duong cheo la :"<<a.duongcheo()<<endl;

    
    /* code */
    return 0;
}
