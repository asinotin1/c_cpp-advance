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

