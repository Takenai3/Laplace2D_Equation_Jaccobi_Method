

# Solution: 2D Laplace Equations - Jacobi Methods

Chương trình tìm nghiệm phương trình Laplace 2D bằng phương pháp Jacobi.

## Thuộc tính

Code bởi: Nhóm 5

Ngôn ngữ sử dụng: C

Đầu vào dữ liệu: bàn phím

Đầu ra dữ liệu: màn hình

## Input

Thông tin của lưới điểm ban đầu với điều kiện biên Dirichlet cố định (Fixed Dirichlet Boundary Condition), bao gồm các thông số:

+ Sai số mong muốn *k*.
+ Số **dòng** *Nx* của lưới điểm (Nx là số tự nhiên lớn hơn 2).
+ Số **cột** *Ny* của lưới điểm (Ny là số tự nhiên lớn hơn 2).
+ Điều kiện biên **trên** của lưới điểm.
+ Điều kiện biên **dưới** của lưới điểm.
+ Điều kiện biên **trái** của lưới điểm.
+ Điều kiện biên **phải** của lưới điểm.

## Output

Thông tin của lưới điểm thu được sau khi chạy thuật toán, bao gồm các thông số:

+ Tổng số lần lặp *n*.
+ Lưới điểm được biểu diễn dưới dạng một bảng gồm *Nx* dòng, *Ny* cột, trong đó giá trị mỗi điểm là một số thập phân lấy đến *6* chữ số sau dấu phẩy.

## Ví dụ

### Input 1
```
Nhap sai so:
0.000001
Nhap so dong:
4
Nhap so cot:
5
Nhap dieu kien bien tren:
8.9
Nhap dieu kien bien duoi:
-3.6
Nhap dieu kien bien trai:
0
Nhap dieu kien bien phai:
0
```
### Output 1

```
Tong so lan lap: 29
Luoi thu duoc:
  8.900000   8.900000   8.900000   8.900000   8.900000
  0.000000   3.144720   3.795030   3.144720   0.000000
  0.000000  -0.116150  -0.009318  -0.116150   0.000000
 -3.600000  -3.600000  -3.600000  -3.600000  -3.600000
```

