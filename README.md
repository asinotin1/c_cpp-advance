# c_cpp-advance
#bài 1 : học về compiler trong gcc với cú pháp : gcc- E main.c -o main.i
có thể thay thế main.i= main.h sẽ ra file của h

#bài 2 : học về tiền xử lý ( macro) có thể dùng macro như các hàm để chương trình chạy nhanh hơn

#bài 3 : học về cách nhập các dữ liệu và tính mà không cho trước các dữ liệu cụ thể
ta dùng thư viện stdrag
Header file có tên stdarg.h trong Thư viện C định nghĩa một kiểu biến va_list và 3 macro mà có thể được sử dụng để lấy các tham số trong một hàm khi số tham số là chưa được biết (ví dụ như số tham số là có thể biến đổi).

Các biến được định nghĩa trong stdarg.h
Sau đây là kiểu biến được định nghĩa trong stdarg.h:

va_list: Đây là một kiểu phù hợp để lưu trữ thông tin cần thiết bởi ba macro là va_start(), va_arg() và va_end().


#bài 4 : học về hàm
Biến cục bộ bình thường: sau khi gọi thì biến khởi tạo giá trị biến và sẽ thu hồi địa chỉ trên bộ nhớ Ram khi chương trình kết thúc khỏi biến đó, lần thứ hai gọi biến thì chương trình sẽ khởi tạo lại giá trị biến từ đầu và có thể giống hoặc không địa chỉ trên bộ nhớ so với lần gọi đầu.

vidu: uint8_t temp = 0; printf("temp: %d\n", temp); temp++;

Biến cục bố dùng static: khi gọi thì biến khởi tạo giá trị chỉ một lần và cố định địa chỉ giá trị đó tồn tại hết vòng đời của chương trình(sau khi kết thúc thì mới thu hồi lại địa chỉ trên bộ nhớ Ram), và lần gọi thứ hai của biến thì giá trị sẽ được tiếp tục.

vidu: static uint8_t temp = 0; printf("temp: %d\n", temp); temp++;

Biến toàn cục static chỉ có giá trị trong phạm vi file chứa nó, không extern sang file khác được còn biến cục bộ thì được.

/Extern(4_2_test.c, 4_3_extern.c):

ta có file1 có biến int a và file2. khi ta muốn sử dụng int a của file1 vào file2 thì dùng extern (extern int a)

không được khởi tạo, giá trị biến tại file extern chỉ được gọi, chỉ được ở file (test)

vì runcode chỉ build được một file duy nhất nên ta dùng:

(gcc file1.c file2.c -o file1) file1 là file dùng extern.

gcc 4_3_extern.c 4_2_test.c -o 4_3_extern

./4_3_extern (./file1)

/Register

ALU(bộ xử lý tính toán), Register(thanh ghi), RAM (cấu trúc vi xử lý gồm RAM và Register) vidu: int a = 5; a++;

    RAM(a=5) -> Register(a=5 và phép toán) -> ALU(thực hiện a++ =6)
                                              
    RAM(nhận kết quả từ Register) <- Register(nhận kết quả từ ALU) <-
vì Register có bộ nhớ giới hạn nên chỉ ưu tiên dùng Register cho những biến cần tốc độ xử lý cao, còn lại tất cả được lưu trên RAM.

//4.5 volatile

Trong lập trình nhúng (Embedded System), ta rất thường hay gặp khai báo biến với từ khóa volatile. Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler.

Thông báo cho compiler không tối ưu hàm đã được khởi tạo sẵn( sử dụng giá trị đã được khởi tạo từ trước)

# bài 5: phân vùng nhớ

•	Text :
– Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
– Chứa khai báo hằng số trong chương trình (.rodata)

•	Data:
– Quyền truy cập là read-write.
– Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
– Được giải phóng khi kết thúc chương trình.

•	Bss:
– Quyền truy cập là read-write.
– Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
– Được giải phóng khi kết thúc chương trình.

•	Stack:
– Quyền truy cập là read-write.
– Được sử dụng cấp phát cho biến local, input parameter của hàm,…
– Sẽ được giải phóng khi ra khỏi block code/hàm

•	Heap:
– Quyền truy cập là read-write.
– Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
– Sẽ được giải phóng khi gọi hàm free,…
# bài 6: 
.struct:

int8_t 		1 byte signed		-128 to 127

uint8_t		1 byte unsigned		0 to 255

int16_t		2 bytes signed		-32768 to 32767

uint16_t	2 bytes unsigned	0 to 65535

int32_t		4 bytes signed		-2147483648 to 2147483647

uint32_t	4 bytes unsigned	0 to 4294967295

int64_t		8 bytes signed		-9223372036854775808 to 9223372036854775807

uint64_t	8 bytes unsigned	0 to 18446744073709551615

Là kiểu dữ liệu do người dùng tự định nghĩa giống như int, double
Sử dụng typedef để định nghĩa ngắn gọn lại
vidu: typedef struct { int ngay; int thang; int nam; }typeDate;

/Sizeof_Struct(6_2_SizeofStruct.c):

căn cứ vào member có kích thước lớn nhất để lấy kích thước lớn nhất cho từng member sau mỗi lần quét các member đó.

Ta có kích thước byte lớn nhất của các lần quét là là Z byte

Quét "lần 1" có X byte: gồm có A byte sử dụng và B byte bộ nhớ đệm trong Z byte.

Quét "lần 2" có Y byte, nhưng so sánh kích thước của B byte bộ nhớ đệm lần quét 1 và kích thước lần quét 2.

Nếu kích thước lần quét 2 nhỏ hơn kích thước Zbyte bộ nhớ đệm lần quét 1 thì ta đưa "lần 2" vào sử dụng bộ nhớ đệm của lần quét 1.
Nếu kích thước lần quét 2 lớn hơn kích thước Zbyte bộ nhớ đệm lần quét 1 thì phải sử dụng kích thước lần quét 2 là Z byte.
Các lần quét tiếp theo tương tự

vidu:

Căn cứ vào member có kích thước lớn nhất là "thang"=4 byte nên mỗi lần quét các member khác cũng có kích thước lớn nhất là 4byte

uint8_t ngay;//1 byte = 1 byte + 3byte bộ nhớ đệm = 4 byte (sử dụng 1byte + 3 byte không sử dụng đến)

So sánh thì lần quét 2 bằng 4 lớn hơn 3byte bộ nhớ đệm lần quét 1 ==> sử dung kích thước lần quét 2

uint32_t thang;//4 byte = 4 byte (sử dụng hết 4 byte)

Vì kích thước lần quét 2 đã sử dụng hết nên quét 3 ta sử dụng kích thước của lần quét 3.

uint16_t nam;//2 byte = 2 byte + 2byte bộ nhớ đệm = 4 byte(sử dụng 2 byte + 2 byte không sử dụng đến)
==>sizeof ngay,thang và nam là:(1byte + 3byte bộ nhớ đệm) + 4byte + (2byte + 2byte bộnhớ đệm) = 12byte

vidu 2:

uint8_t ngay;//1 byte = 1 byte + 7 byte bộ nhớ đệm= 8 byte
uint64_t tuan;// 8 byte = 8 byte
uint16_t nam;// 2 byte = 2 byte + 6 byte bộ nhớ đệm = 2 byte + 4 byte + 2 byte bộ nhớ đệm = 8 byte 
uint32_t thang;// 4 byte = 0 
Kích thước mỗi lần quét lớn nhất là 8 byte.

uint8_t ngay;// 1 byte = 1 byte + 7 byte đệm
    So sánh thấy 7 byte đệm của "ngay" không chứa đủ 8 byte của "tuan" nên kích thước của "tuan" là 8byte sau lần quét thứ 2.
uint64_t tuan;// 8byte = 8 byte
    Kích thước của "tuan" được sử dụng hết nên kích thước "thang" được sử dụng trong 8 byte sau lần quét thứ 3.
uint16_t thang;// 2 byte = 2 byte + 6 byte đệm
    Ta có 6 byte bộ đệm của "thang" chứa đủ 4 byte của "nam" nên 4 byte của "nam" được sử dụng ở trong 6 byte bộ đệm của "thang".
    ==>2 byte + 4 byte + 2 byte bộ nhớ đệm.
uint32_t nam;// 4 byte = 0
==> sizeof = 24byte

vidu 3:

    uint8_t ngay[3];//1 byte = 3 byte + 1 byte đệm =  4 byte
    uint16_t nam[4];// 2byte = 8 byte 
    uint32_t thang[5];// 4 byte = 20 byte
kích thước mỗi lần quét là 4byte;

    uint8_t ngay;// 1byte
    uint8_t ngay;// 1byte
    uint8_t ngay;// 1byte
    ==> 3 byte + 1byte đệm = 4 byte

    uint16_t nam;//2byte
    uint16_t nam;//2byte
    uint16_t nam;//2byte
    uint16_t nam;//2byte
    ==> 4 byte + 4 byte = 8 byte

    uint32_t thang;//4byte
    uint32_t thang;//4byte
    uint32_t thang;//4byte
    uint32_t thang;//4byte
    uint32_t thang;//4byte
    ==> 20 byte
==> sizeof = 32 byte

vidu 4:

kích thước mỗi lần quét là 4 byte.

    uint8_t ngay[3];//1 byte = 3byte + 1 byte đệm = 4 byte
    uint32_t thang[4];//4 byte = 16 byte
    uint16_t nam[5];// 2 byte = 8 byte + (2 byte + 2 byte bộ đệm) = 12 byte
==> sizeof = 32 byte

vidu 5:

    kích thước mỗi lần quét là 8 byte: 
    uint8_t ngay[3];//1 byte = 3 byte + 5 byte đệm = 8 byte
    uint32_t thang[4];// 4 byte 
    = 4 byte lần đầu sử dụng trong 5 byte bộ đệm của "ngay" (3 byte + 4 byte + 1 byte đệm)
    2*4 =8 byte + (4 byte + 4 byte đệm) = 16 byte

    unit64_t tuan[3];//8 byte = 3 * 8 =  24 byte
    uint16_t nam[5];// 2byte = 2*4 =  8 byte + (2 byte + 6 byte đệm) = 16 byte
    
==> sizeof = 64 byte

/UNION(6_3_union.c)

Giống như Struct, Union cũng là kiểu dữ liệu do ngườ dùng tự định nghĩa.

Giá trị của các biến trong Union đều giống nhau và bằng giá trị của biến được khởi tạo cuối cùng vì các biến trong Union đều cùng một địa chỉ nên khi khởi tạo thì giá trị sau sẽ ghi đè lên giá trị trước.

Kích thước của Union là kích thước của member lớn nhất.

vidu:

          #include <stdio.h>
          #include <stdint.h>
          #include <string.h>

          typedef union 
          {

          uint8_t var1[5]; // char
          uint16_t var2[2]; // long

          }typeData;

          int main(int argc, char const *argv[])
          {
              typeData data ;

              for(int i = 0; i < 5; i++){
                  data.var1[i] = i; // 0 1 2 3 4
              }

              for(int i = 0; i < 2; i++){
                  data.var2[i] = 2*i ;  // 0 2
              }

              for(int i = 0; i < 5 ; i++){
                  printf("test1: %d\n", data.var1[i]);
              }
          
              return 0;
          }
          
kết quả là: 0 0 2 0 4

var1 có kết quả là: 0 1 2 3 4 (var1 có giá trị 1 byte nên mỗi ô là một giá trị i)
var2 có kết quả là: 0 0 2 0 (vì var 2 có giá trị là 2 byte nên ô lưu trữ đầu tiên là giá trị i và ô lưu trữ thứ 2 là giá trị 0)
do cùng một địa chỉ nên var2 sẽ ghi đè lên var1 sau đó var2 = var1
do đó kết quả cuối cùng là: 0 0 2 0 4
/TỔNG KẾT.

    - Struct:
        + là kiểu dữ liệu do người dùng tự định nghĩa;
        + Kích thước là tổng các member cộng lại (byte sử dụng và byte bộ nhớ đệm);
        + Mỗi member của struct đều có địa chỉ riêng nên khi thay đổi giá trị của một member thì không ảnh hưởng đến member khác.

    - Union:
        + là kiểu dữ liệu do người dùng tự định nghĩa;
        + Kích thước của union sẽ là kích thước của member lớn nhất;
        + Các member trong Union đều dùng chung một địa chỉ nên khi thay đổi một giá trị member thì sẽ ảnh hưởng đến giá trị các member khác
        
#bài 7

biến : jmp_buf.
Đây là một kiểu mảng được sử dụng để giữ thông tin cho macro setjmp() và hàm longjmp().

Macro setjmp và hàm longjmp được sử dụng cùng nhau chủ yếu khi xử lý lỗi hay xử lý ngoại lệ. Có thể nói rằng, sử dụng kết hợp macro setjmp và hàm longjmp là một phiên bản go to mạnh mẽ hơn.Macro setjmp và hàm longjmp được sử dụng cùng nhau chủ yếu khi xử lý lỗi hay xử lý ngoại lệ. Có thể nói rằng, sử dụng kết hợp macro setjmp và hàm longjmp là một phiên bản go to mạnh mẽ hơn.

throw: Một chương trình ném một Exception khi một vấn đề xuất hiện. Việc này được thực hiện bởi sử dụng từ khóa throw trong C++.

catch: Một chương trình bắt một Exception với một Exception Handler tại vị trí trong một chương trình nơi bạn muốn xử lý vấn đề đó. Từ khóa catch trong C++ chỉ dẫn việc bắt một exception.

try: Một khối try có thể được bắt bởi một số lượng cụ thể exception. Nó được theo sau bởi một hoặc nhiều khối catch.

#bài 8 : pointer

Trong bài này chúng ta sẽ tìm hiểu về con trỏ (pointer) trong ngôn ngữ lập trình C: Con trỏ là gì, cách sử dụng nó như thế nào, cách biểu diễn trong ngôn ngữ C, và các bài tập thực hành.

Con trỏ là một tính năng nâng cao rất hay của ngôn ngữ lập trình C/C++, nó giúp ta xử lý các bài toán về danh sách liên kết và có thể thay thế cho mảng trong một số trường hợp.

Khi bạn khai báo một biến var với kiểu dữ liệu int thì trình biên dịch sẽ gắn biến var đó tới một địa chỉ trong bộ nhớ, địa chỉ này sinh ra ngẫu nhiên và có đồ dài bằng với kiểu dữ liệu của biến.

Con trỏ (pointer) là một biến đặc biệt, dùng để lưu trữ địa chỉ lưu trữ chứ không phải là giá trị như biến thông thường.

Khai báo con trỏ: Để khai báo biến con trỏ thì ta sử dụng ký tự sao (*) dặt phía trước tên biến.

kỹ thuật 2 con trỏ : https://devera.vn/blog/our-blog-1/post/thuat-toan-trong-lap-trinh-phan-3-two-pointer-va-sliding-window-71

#bài 10: linked list

Trong ngôn ngữ lập trình C, một danh sách liên kết (linked list) là một cấu trúc dữ liệu được sử dụng để lưu trữ một tập hợp các phần tử có thể thay đổi kích thước trong khi chương trình đang chạy. Danh sách liên kết bao gồm một chuỗi các nút (node), mỗi nút chứa một giá trị và một con trỏ (pointer) đến nút tiếp theo trong danh sách. Vì vậy, danh sách liên kết có thể được xem như một chuỗi các "hộp" được nối với nhau bởi các con trỏ.

Để tạo một danh sách liên kết trong C, ta cần định nghĩa một cấu trúc dữ liệu gồm hai thành phần: giá trị và con trỏ. Ví dụ, đoạn mã sau định nghĩa một cấu trúc dữ liệu để lưu trữ một số nguyên và một con trỏ đến nút tiếp theo:

struct Node {
    int data;
    struct Node* next;
};

Sau đó, để tạo ra một danh sách liên kết, ta sử dụng các toán tử cấp phát bộ nhớ động như malloc() để tạo ra các nút mới và sử dụng các con trỏ để liên kết các nút lại với nhau. Ví dụ, đoạn mã sau tạo ra một danh sách liên kết đơn giản gồm ba nút chứa các giá trị 1, 2 và 3:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return 0;
}

Trong đoạn mã trên, ta đầu tiên định nghĩa ba con trỏ head, second và third để lưu trữ ba nút của danh sách liên kết. Sau đó, ta sử dụng malloc() để cấp phát bộ nhớ động cho các nút và gán địa chỉ của chúng cho các con trỏ tương ứng. Cuối cùng, ta gán giá trị và con trỏ của từng nút để liên kết chúng với nhau và tạo ra danh sách liên kết hoàn chỉnh.


# BAI11: STACK

### 1.Tổng quan
Ngăn xếp (STACK) là một danh sách tuyến tính, trong đó cho phép thêm và loại bỏ một phần tử khỏi ngăn xếp luôn luôn thực hiện ở một đầu gọi là đỉnh (top).

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai11_stack.png?raw=true)

### 1.1.Hàm kiểm tra ngăn xếp đầy

// return true if stack empty else false

            bool isEmpty(){
            if(i == -1){
                return true;
            }
            else{
                return false;
            }
        }
### 1.2.Hàm kiểm tra ngăn xếp rỗng
 // return true if stack is full else false

            bool isFull(){
                if(i == SIZE - 1){
                    return true;
                }
                else{
                    return false;
                }
            }

### 1.3.Hàm thêm một khối vào ngăn xếp
// to insert an elememt into the stack

            void push(uint8_t stack[], uint8_t value){
                if(isFull() == true){
                    printf("stack is full\n");
                }
                else{
                    ++i;
                    stack[i] = value;
                }
            }
### 1.4.Hàm xóa một khối khỏi ngăn xếp
// to remove an element from the stack

        void pop(uint8_t stack[]){
            if(isEmpty() == true){
                printf("stack is empty\n");
            }
            else {
                stack[i--] =='\0';
            }
        }
### 1.6.Hàm trả về một khối cảu ngăn xếp     
// return the top element of the stack

        uint8_t top (const uint8_t stack[]){
            return stack[i];
        }
### 1.7.Hàm trả về kích thước của ngăn xếp       
// return the size of the stack

        uint8_t size(){
            return i + 1;
        }

# BAI12_QUEUE(HÀNG ĐỢI)
## 1.Tổng quan
Hàng đợi là một danh sách tuyến tính trong đó, phép bổ sung một phần tử vào hàng đợi được thực hiện ở một đầu, gọi là cuối hàng(rear) và phép loại bỏ một phần tử được thực hiện ở đầu kia, gọi là đầu hàng(front).

Cơ cấu của hàng đợi là vào ở một đầu, ra ở một đầu, phần tử vào trước thì ra trước, phầm tử vào sau thì ra sau.

Hàng đợi còn được gọi là danh sách kiểu FIFO(First In First Out)

![](https://github.com/langtoan22/image_C_Cpp_Advanced/blob/main/bai12_queue.png?raw=true)

- quy ước: 

        rear = -1
        front = -1

- biến thể của queue: 
    + có hai trường hợp queue rỗng: front = rear = -1(khi chưa gán data), rear = front(khi lấy hết data)

# BAI13_CÂY NHỊ PHÂN

# BÀI14_CLASS
### 1. CLASS

là một phần trong OOP, một địn nghĩa chung của các object.

Class gồm 2 phần: 
- Thuộc tính(attribue/property);
- hương thức(method, behavior). 

là các trường dữ liệu mô tả thuộc tính và hành động của lớp

Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa

Object(đối tượng): là một thực thể của Class


**vidu:** Class connguoi bao gồm: 
- Các thuộc tính: tên, tuổi, địa chỉ, ngày sinh, ...
- Các hành động: đi lại, ăn, ngủ...
khi đó Object là một người cụ thể nào đó.
### 1.KHAI BÁO MỘT CLASS 

        class tênclass{
            public: method();
            private: property
        };
            void tênclass :: method(){
            };
        int main
            tenclass object;
            object.method();


### 2.Phạm vi truy cập của class (Acess modifier)

- public: object có thể truy cập đến được
- private: chỉ có thể truy cập trong class đó;
- protected: cho phép các class con có thể truy cập đến và sửa được; các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó
### 3.Method declaration
Phương thức cũng giống như một hàm bình thường.

Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong
lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
### 4. Hàm dựng

Constructor(hàm khởi tạo): một hàm được khởi tạo khi khai báo một thực thể mới(object), nó có cùng tên với tên Class và không có kiểu trả về.

Destructor(hàm huỷ): nó có cùng tên với tên Class và không có kiểu trả về. nhưng có dấu ~ trước hàm

### 5.Static member

Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function 

Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static

các object đều dùng chung một địa chỉ khi trỏ đến một property sau khi khai báo 1 static .

**vidu**:

        class tênclass{
                    public: method();
                    private: property
                    static int mssv
                };
                    int tênclass :: mssv;

                    void tênclass :: method(){
                    };
                int main
                    tenclass object;
                    object.method();
// :: toán tử phạm vi

vidu về một class hoàn chỉnh: 

        #include <iostream>
        #include <string>
        using namespace std ;

        class sinhvien{
            public://pham vi truy cap
                void setthongtin();
                void hienthi(); //method

            private: 
                int tuoi;// property
                int lop;
                string ten;
        };

            void sinhvien::setthongtin(){
                    cout << "nhap vao ten:\n";
                    cin >> ten;
            }

            void sinhvien::hienthi(){
                cout <<"ten:" << ten <<"\n";
            }

        int main(int argc, char const *argv[])
        {
            sinhvien sv1; //Oject thuoc class sinh vien

            sv1.setthongtin();
            sv1.hienthi();

            return 0;
        }

# BÀI15_OOP

gồm 2 phần là class và object:
- class là một định nghĩa chung của object;
- object là một đối tượng chủ thể riêng biệt trong định nghĩa của class.
 ## 1. OOP

- Object-oriented programming(OOP): xoay quang các đối tượng, dữ liệu thay vì xoay quành các hàm và thủ tục
- Cố gắng mô phỏng các đối tượng trong thực tế thành các đối tượng trong ngôn ngữ lập trình thông qua các trường dữ liệu (data field) thuộc tính (attributes) và các hành động(behavior)

 ví dụ; con người có các thuộc tính tên tuổi, địa chỉ và các hành  động đi đứng ngồi ...
 - OOP tập chung vào các đối tượng thay vì logic phù hợp với các chương trình lớn và hay active, bảo trì...
 - Điểm mạnh của OOP: có khả năng tái sự dụng lại code(code reusability), mở rộng(scalability), và hiệu quả(efficiency).

## 2.CÁC TÍNH CHẤT CỦA OOP

### 2.1.TÍNH KẾ THỪA(Inheritance)

- Đặc tính này cho phép xây dựng một lớp mới có
thể có sẵn các đặc tính mà các lớp khác đã có
thông qua kế thừa.
- Điều này cho phép các lớp chia sẻ hay mở rộng các
đặc tính sẵn có mà không phải tiến hành định nghĩa
lại

#### 2.1.1.XÂY DỰNG KẾ THỪA

        class <tenClass2>:<phạm vi kế thừa> <tenClass1>
        {
        //Nội dung lớp dẫn xuất
        };

Khi tenClass1 để phạm vi truy cập của property là private thì tenClass2 không kế thừa được

vidu: 

            class tenClass1{
                public: method();
                        property
            };
            void tenClass1 :: method(){
                
            };
        

        //tenclass2 kế thừa toàn bộ property và method của tenClass1

            class tenClass2 : public tenClass1{
                //định nghĩa mới của class con
            };
            void tenClass2 :: method(){
                ghi đè định nghĩa mới dựa trên class cha
            }
            

#### 2.1.2. PHẠM VI KẾ THỪA (Acess mode)

- **Public**: Khi đó phạm vi truy cập(acess modifier) của class con sẽ giống của class cha.

- **Private**: khi đó tất cả các property và method của class cha sẽ có phạm vi truy cập( acess modifier) là private ở class con, khi đó các đối tượng (object) sẽ không truy cập được vào các thông tin(property và method) của class cha mà class con đã kế thừa thay và chỉ truy cập được vào các thông tin mà class con đã định nghĩa.
- **protected**: khi đó tất cả thông tin( property và method) của class cha khi để phạm vi truy cập( acess modifier) là pubic thì class con sẽ là protected.


**vidu:** 

        #include <iostream>
        #include <string>

        using namespace std;
        class DoiTuong{
            public:
                string ten;
            
                void NhapThongTin(string ten);
                void HienThi();
        };

            void DoiTuong :: NhapThongTin(string ten, int tuoi, int lop){
                DoiTuong :: ten = ten;
            }

            void  DoiTuong ::HienThi(){
                cout << "day la class DoiTuong:\n";
                cout <<"ten: " <<ten<<endl;
            }

        //class SinhVien kế thừa class DoiTuong
        class SinhVien :public DoiTuong{
                
        };

        int main(int argc, char const *argv[])
        {
            SinhVien sv1;

            sv1.NhapThongTin("Hoang", 17, 11);
            sv1.HienThi();
            return 0;
        }

####  GHI ĐÈ (overridding)

Khi class con muốn thêm property và sử dụng lại method của class cha.
khi đó class con định nghĩa lại method khi cần thêm các property;

### 2.2. TÍNH ĐA HÌNH(polymorphism)
- các method trong class sẽ phân biệt dựa vào các input parameter.

### 2.3.TEMPLATE
- Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- Template trong C++ có 2 loại đó là function template & class template.
- Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

### 2.4. TÍNH TRỪU TƯỢNG(Abstraction)
- trong lập trình hướng đối tượng là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý.
- Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.
- Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà gạo có thể nấu thành cơm

###  2.5.TÍNH ĐÓNG GÓI(Encapsulation)
- Khi khai báo property thì phải khai báo ở phạm vi truy cập(acess modifier) là private hoặc protected không được phép khai báo ở public, phòng trường hợp người dùng truy cập trực tiếp và thay đổi giá trị dẫn đến sai chương trình.

# BÀI16

### 1.namespace

Định nghĩa vùng nhớ, mỗi namespace sẽ định nghĩa vùng nhớ riêng biệt hay con gọi thư viện riêng, cho phép đặt tên hai biến, class, mảng... trùng tên với nhau trong 2 thư viện khác nhau.

**using namspace**: gọi một thư viện được khai báo trước đó 

### 2.virtual fuction 
Chỉ dùng trong class

Còn được gọi là hàm ảo, khi các phương thức của classs cha dùng virtual thì class con kế thừa sẽ load lại phương thức và hiển thị phương thức đã được định nghĩa và ghi đè

class con khi kế thừa và ghi đè thì vẫn trên phân vùng địa chỉ của class cha, nên khi không dùng virtual thì khi gọi các phương thức đã được định nghĩa và ghi đè mới của class con thì sẽ hiện các phương thức của class cha.

### 3.string
Sử dụng thư viện: include< string>
### 4.vector

Sử dụng thư viện: include< vector>

vector giống như mảng động(linklist) có thể thay đổi được kích thước tuy nhiên các địa chỉ trong vector là liền kề nhau.

Cú pháp: vector <kiểu dữ liệu> ten_vector

Các hàm vector: 
- Thêm phần tử: ten_vector.**push_back()**;
    >array.push_back(5);
- Xóa phần tử cuối: ten_vector.**pop_back()**;
- Chèn phần tử: ten_vector.**insert(array.begin()+giá trị địa chỉ dịch chuyển tính từ vị trí đầu,giá trị phần tử cần chèn)**
    >array.insert(array.begin()+2, 8);
- Tạo một mảng gồm các phần tử cùng giá trị: ten_vector. **assign(số lượng phần tử, giá trị phần tử)**; ví dụ tạo 4 phần tử có giá trị là 3
    >array.assign(4,3);
- kích thước vector: ten_vector.**size()**;

kĩ thuật duyệt( for cải tiến) qua các phần tử: 
- for(datatype ten_bien : ten_vector){
    printf("%d\n", ten_bien);
}

Các địa chỉ trong vector sẽ được gán cho ten_bien và in ra cho đến hết các phần tử trong vector.

