#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string namebook;
        string author;
        unsigned int year;
        unsigned int soluong;

    public:
        Book(string namebook, string author, unsigned int year, unsigned int soluong) {
            this->namebook = namebook;
            this->author = author;
            this->year = year;
            this->soluong = soluong;
        }

        void thongtin() {
            cout << "Ten sach: " << namebook << endl;
            cout << "Tac gia: " << author << endl;
            cout << "Nam xuat ban: " << year << endl;
            cout << "So luong: " << soluong << endl;
        }

        bool borrow_book(string name) {
            if (name == namebook) {
                if (soluong > 0) {
                    soluong--;
                    cout << "Muon sach thanh cong" << endl;
                    return true;
                } else {
                    cout << "Het sach de muon" << endl;
                    return false;
                }
            } else {
                cout << "Khong co sach can muon" << endl;
                return false;
            }
        }

        bool give_book(string name) {
            if (name == namebook) {
                soluong++;
                cout << "Da tra dung sach" << endl;
                return true;
            } else {
                cout << "Khong phai sach da muon" << endl;
                return false;
            }
        }
};

int main() {
    Book sach1("Toi thay hoa vang tren co xanh", "tran quang luan", 2000, 10);
    sach1.thongtin();
    sach1.borrow_book("Toi thay hoa vang tren co xanh");
    sach1.thongtin();
    sach1.give_book("Toi thay hoa vang tren co xanh");
    sach1.thongtin();
    return 0;
}
