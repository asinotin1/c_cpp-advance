#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class animal
{
    private:
    string name;
    int age;
    double weight;
    double height;
    public:
      string getName() {
  	return this->name;
  }
  void setName(string name) {
  	this->name = name;
  }


    int getAge() {
    	return this->age;
    }
    void setAge(int age) {
    	this->age = age;
    }


    double getWeight() {
    	return this->weight;
    }
    void setWeight(double weight) {
    	this->weight = weight;
    }
     double getHeight() {
    	return this->height;
    }
    void setHeight(double height) {
    	this->height = height;
    }

    double BMI()
    {
        double bmi;
        bmi=weight/pow(height,2);
        return bmi;
    }
    string sosanh(animal a)
    {
        if(age>a.age)
        {
            
            return age + " lon tuoi hon"+a.getName();
        }
        else if(age=a.age)
        {
            return age+ " bang tuoi "+a.getName();
        }
        else
        {
            return age + "nho tuoi hon" +a.getName();
        }
    }
};

int main(int argc, char const *argv[])
{
    animal dog;
    dog.setName("bin");
    dog.setAge(12);
    dog.setHeight(33.5);
    dog.setWeight(32);
    animal cat;
    cat.setName(" mimi");
    cat.setAge(13);
    cat.setHeight(35);
    cat.setWeight(44);
    double k=dog.BMI();
    string h= dog.sosanh(cat);
    cout<<"BMI cua bin :"<<k<<endl;
    cout<<h<<endl;
    
    
    return 0;
}
