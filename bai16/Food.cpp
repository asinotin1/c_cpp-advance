#include <iostream> 
#include <list> 
#include <cstdint>
using namespace std; 

typedef enum{
    QUAN_LY = 1,
    NHANVIEN=2, 
}TypeSelection;

class Mon{
    private: 
    uint8_t ID; 
    string TEN;
    double GIA;
  
    void setTen(); 
    void setGia(); 
    public: 
    Mon(uint8_t id, string TEN, int GIA); 
    int setID(); 
    int getID(); 
    string getTen(); 
    double getGia(); 
    void getDanhSachMon();
}; 
Mon::Mon(uint8_t id, string TEN, int GIA){
    this->ID = id;
    this->TEN = TEN; 
    this->GIA = GIA; 
}
void Mon::getDanhSachMon(){
cout << "ID : " << getID() << endl; 
cout << "Ten mon an  : " << getTen() << endl; 
cout << "Gia : "<< getGia() << endl;  
}
int Mon::setID(){
    static int id = 100; 
    this->ID = id; 
    id++; 
    return Mon::ID;
}
int Mon::getID(){
    return this->ID;
}
string Mon::getTen(){
    return Mon::TEN; 
}
double Mon::getGia(){
    return Mon::GIA; 
}

class QuanLy{
private: 
int SOBAN;
void themMon();
void suaMon();
void xoaMon(); 
void thietlapSoBan();
public:
list<Mon>DATABASE;
QuanLy();
list<Mon> getDatabase();
int getSoBan(); 
void Select_Quanly();
void hienThiDanhSachMon();
}; 
list<Mon> QuanLy::getDatabase(){
    return this->DATABASE; 
}
void QuanLy::thietlapSoBan(){
    uint8_t soban; 
    cout << "Nhap vao so ban an: " <<endl; 
    cin >> soban;
    QuanLy::SOBAN = soban;
}
int QuanLy::getSoBan(){
    return this->SOBAN; 
}
void QuanLy::hienThiDanhSachMon(){
    for(auto listmon : DATABASE) {
        cout << "id : " <<  listmon.getID() << endl; 
        cout << "ten mon : " << listmon.getTen() << endl; 
        cout << "gia : " << listmon.getGia() << endl; 
    }
}

void QuanLy::themMon(){
    string TEN; 
    double GIA; 
    cout << "Nhap vao ten mon an moi " << endl; 
    cin >> TEN; 
    cout << "Nhap gia mon an moi : " << endl; 
    cin >> GIA; 

    Mon NEW(NEW.setID(),TEN,GIA); 
    DATABASE.push_back(NEW);
    cout << "da them mon moi : " << endl;  
}
void QuanLy::suaMon(){

    cout << "1.doi ten " << endl; 
    cout << "2.doi gia " << endl; 
    cout << "0.Quay lai " << endl; 
}
void QuanLy::xoaMon(){
    int id; 
    cout << "Nhap vao id mon can xoa " << endl; 
    cin >> id; 
    auto position = DATABASE.begin(); 
    for (auto item : DATABASE){
        if (item.getID() == id){
            DATABASE.erase(position); 
        }
        position++;
    }
}

void QuanLy::Select_Quanly(){
     while(1){
    int phim; 
        cout << "1.Them mon " << endl; 
        cout << "2.Sua mon " << endl; 
        cout << "3.Xoa mon " << endl; 
        cout << "4.Danh sach mon " << endl; 
        cout << "5.Thiet lap so ban " << endl; 
        cout << "0.Quay lai " << endl;
        cout << "vui long  chon : " << endl; 
        cin >> phim;
    switch (phim)
    {
    case 1:
        themMon();
        break;
    case 2: 
        suaMon(); 
        break; 
    case 3: 
        xoaMon(); 
        break; 
    case 4: 
        hienThiDanhSachMon(); 
        break; 
    case 5: 
        thietlapSoBan(); 
        break; 
    case 0: 
        return; 
    default:
        break;
    }
    }
}
class thongTinBan{
private: 
    uint8_t SOBAN;
    bool TRANGTHAI;
    typedef struct{
        Mon MON_AN; 
        int SO_LUONG; 
    }TypeMon; 
    list<TypeMon> DATABASE_MON;
public:
    thongTinBan(uint8_t SOBAN, bool TRANGTHAI); 
    int getSoBan(); 
    bool getTrangThai(); 
    void setTrangThai();
    void getDanhSachMon();
    void themMon(list<Mon> database , thongTinBan a);
    void suaMon(int id, int SO_LUONG);
    void xoaMon(int id);

}; 
thongTinBan::thongTinBan(uint8_t SOBAN, bool TRANGTHAI){
    this->SOBAN = SOBAN;
    this->TRANGTHAI = TRANGTHAI;
}
int thongTinBan::getSoBan(){
    return thongTinBan::SOBAN; 
}
void thongTinBan::setTrangThai(){
    thongTinBan::TRANGTHAI = 1; 
}
bool thongTinBan::getTrangThai(){
    return thongTinBan::TRANGTHAI; 
}
void thongTinBan::getDanhSachMon(){
    for(auto listmon : DATABASE_MON){
        cout << "Ten mon : " << listmon.MON_AN.getTen() << endl; 
        cout << "So luong : " << listmon.SO_LUONG << endl; 
    }
}
void thongTinBan::xoaMon(int id){
    cout << "Nhap vao id " << endl; 
    cin >> id; 
    auto position = DATABASE_MON.begin(); 
    for (auto item : DATABASE_MON){
        if (item.MON_AN.getID() == id){
             DATABASE_MON.erase(position); // xóa phần tử 
        } else {
            cout << "loi ID khong xuat hien " << endl; 
        }
        position++; 
    }
}
//
void thongTinBan::themMon(list<Mon> database, thongTinBan a){
    int id; 
    int soLuong;
    cout << "Nhap vao id mon can them : " << endl; 
    cin >> id; 
    for (auto  thongtin : database){
        if(thongtin.getID() == id){
            cout << "ID da  ton tai, vui long nhan ID khac : " << endl; 
            cout << "Nhap  so luong mon : " << endl; 
            cin >> soLuong; 
            TypeMon NEW{thongtin,soLuong};
            DATABASE_MON.push_back(NEW);
            cout << "Them mon tai ban thanh cong ! " << endl;  
            if (a.getTrangThai() == 0){
                a.setTrangThai();
        } else { 
            cout << "ID khong ton tai " << endl;
            return;
        }
    }
}
}
void thongTinBan::suaMon(int id, int soLuong){
    cout << "Nhap vao id mon can sua  : " << endl;
    cin >> id; 
    for (auto thongtin : DATABASE_MON){
        if(thongtin.MON_AN.getID() == id){
            cout << "Nhap vao so luong mon thay doi : " << endl; 
            cin >> soLuong; 
            thongtin.SO_LUONG = soLuong;
            cout << "Thay doi so luong mon thanh cong " << endl; 
        } else {
        cout << "ID khong ton tai ! " <<endl; 
        }
    } 
   

}
class NhanVien{
    private: 
    list<Mon> DATABASE_MON_AN;
    list<thongTinBan> DATABASE_BAN;
    void hienThiThongTinBan(); 

    public: 
    NhanVien(list<Mon> DATABASE_MON_AN, int SO_BAN);
    
}; 
NhanVien::NhanVien(list<Mon> database, int SO_BAN){
    if(SO_BAN == 0 && DATABASE_MON_AN.size() == 0){
        cout << "Ban chua nhap danh sach mon an va setup so ban " << endl; 
        return;
    } 
    else
    {
    DATABASE_MON_AN.assign(database.begin(),database.end());
    for (int i = 1; i <= SO_BAN; i++)
    {
        thongTinBan ban(i,false); 
        DATABASE_BAN.push_back(ban); 
    }
    for (auto item : DATABASE_BAN){
        cout << "So ban : " << item.getSoBan() << endl;
        cout << "Trang thai:  " << item.getTrangThai() << endl; 
    }
    int soBanGoiMon; 
    cout << "Nhap vao so ban muon goi mon " << endl; 
    cin >> soBanGoiMon; 
    for (auto item : DATABASE_BAN){
        if (soBanGoiMon == item.getSoBan()){
            int inputTaiBan; 
            cout << " nhan vien :" << endl; 
            cout << "1.Them mon tai ban " << endl; 
            cout << "2.Sua mon tai ban " <<endl; 
            cout << "3.Xoa mon tai ban " << endl; 
            cout << "4.Danh sach mon tai ban " << endl; 
            cout << "5.Thanh toan " << endl; 
            cout << "0.Quay lai " << endl;
            cout << "Ban chon : " << endl; 
            cin >> inputTaiBan; 
            switch (inputTaiBan)
            {
            case 1:
                for (auto item_Mon : database){
                    item_Mon.getDanhSachMon(); 
                }
                item.themMon(database, item); 
                break;
            case 2: 
                for (auto item_Mon : database){
                    item_Mon.getDanhSachMon(); 
                } 
                break;
            case 3: 
                int id3; 
                item.xoaMon(id3);
                break;
            case 4: 
                item.getDanhSachMon(); 
                break; 
            case 5: 
                break; 
            case 0: 
                return; 
            default:
                break;
            }
        } else { 
            cout << "So ban ko hop le " << endl; 
            return; 
        }
    }
}
}
int main(int argc, char const *argv[])
{   QuanLy luan;
    while(true){
    int keyInput = 0;
    cout << "Chuong trinh quan ly quan an " << endl; 
    cout << "1. Quan ly " << endl; 
    cout << "2. Nhan vien " << endl; 
    cout << "Nhap vao : " << endl; 
    cin >> keyInput; 
    switch ((TypeSelection)keyInput)
    {
    case QUAN_LY:
    {
        luan.hienThiDanhSachMon();
        break;
    } 
    case NHANVIEN:{
        
        NhanVien han {luan.getDatabase(),luan.getSoBan()};

        break;
    }
    default: 
        break;
    }
}
    return 0;
}
