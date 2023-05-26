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


