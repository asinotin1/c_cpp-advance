    #include<iostream>
    #include<string>
    #include<map>
    using namespace std;

    int main(int argc, char const *argv[])
    {
        map<string,string> sinhvien;
        sinhvien["name"]="luan";
                // key   value
        sinhvien["age"]="age";
        sinhvien["ID"]="101";
        for(auto i: sinhvien)
        {
            cout<<"key: "<<i.first<<" "<<"value: "<<i.second<<endl;

        }

        return 0;
    }
