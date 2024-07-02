#pragma once 
#include "HeaderC.h"

struct date{
    int ngay;
    int thang;
    int nam;
};
struct admin{
    char ma[50];
    char ten[50];
    double giaNhap;
    double giaBan;
    date ngaySanXuat;
    date hanSuDung;
    int soLuongBan;
    char danhMuc[50];
    double tongThu, tongNhap;
};
//định nghĩa lớp admin bằng AD cho dễ sử dụng
typedef admin AD;

void xoaXuongDong(char x[]){
    size_t len = strlen(x);
    if(x[len-1]=='\n'){
        x[len-1] = '\0';
        }
};
//hàm nhập thông tin sản phẩm
void nhapThongTinSanPham( AD &sp){
    printf("\n");
    printf("\nNhap ma san pham: ");
    fflush(stdin); //xóa dấu enter 
    fgets(sp.ma, sizeof(sp.ma), stdin);
    xoaXuongDong(sp.ma);
    printf("\nNhap ten san pham: ");
    fflush(stdin);
    fgets(sp.ten, sizeof(sp.ten), stdin);
    xoaXuongDong(sp.ten);
    printf("\nGia nhap san pham: ");
    scanf("%lf", &sp.giaNhap);
    printf("\nGia ban san pham: ");
    scanf("%lf", &sp.giaBan);
    printf("\nNhap ngay san xuat: ");
    scanf("%d/%d/%d", &sp.ngaySanXuat.ngay, &sp.ngaySanXuat.thang, &sp.ngaySanXuat.nam);
    printf("\nNhap han su dung: ");
    scanf("%d/%d/%d", &sp.hanSuDung.ngay, &sp.hanSuDung.thang, &sp.hanSuDung.nam);
    printf("\nNhap danh muc san pham: ");
    fflush(stdin);
    fgets(sp.danhMuc, sizeof(sp.danhMuc), stdin);
    xoaXuongDong(sp.danhMuc);
}

//Hàm nhập danh sách sản phẩm 
void nhapDanhSachSanPham(AD sp[], int &n){
    do{
        printf("\nNhap vao so luong san pham: ");
        scanf("%d", &n);
    }while (n<=0);
    for (int i=0; i<n; i++){
        printf("\nNhap vao san pham thu %d: ", i+1);
        nhapThongTinSanPham(sp[i]);
    }
}

//Hàm in thông tin sản phẩm
void inThongTinSanPham(AD sp){
    //chú ý giá tiền dưới dạng VNĐ
    printf("\n%5s \t %15s \t %15.0lf \t %18.0lf \t %18d/%2d/%4d \t %2d/%2d/%4d \t %10s", sp.ma, sp.ten, sp.giaNhap, sp.giaBan, sp.ngaySanXuat.ngay, sp.ngaySanXuat.thang, sp.ngaySanXuat.nam, sp.hanSuDung.ngay, sp.hanSuDung.thang, sp.hanSuDung.nam, sp.danhMuc); 
}

//Hàm xuất danh sách san pham
void xuatDanhSachSanPham(AD sp[], int n){
    printf("\n");
    printf("\n%5s \t %15s \t %10s \t %10s \t %8s \t %8s \t %10s","Ma", "Ten san pham", "Gia nhap san pham (VND)", "Gia ban san pham (VND)","Ngay san xuat", "Han su dung", "Danh muc");
    for (int i = 0; i < n; i++){
    inThongTinSanPham(sp[i]);
    }
}

//Hàm tìm kiếm sản phẩm theo tên 
void timKiemSanPhamTheoTen(AD sp[], int n, char ten[]) {
    int timThay = 0; // Biến kiểm tra xem có sản phẩm nào thỏa mãn không
    for (int i = 0; i < n; i++) {
        if (strstr(sp[i].ten, ten)) {
            inThongTinSanPham(sp[i]);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("\nKhong co san pham nao co ten \"%s\" trong danh sach.\n", ten);
    }
}

//Hàm tìm kiếm sản phẩm theo mã
void timKiemSanPhamTheoMa(AD sp[], int n, char ma[]) {
    int timThay = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(sp[i].ma, ma)) {       
            inThongTinSanPham(sp[i]);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("\nKhong co san pham nao mang ma \"%s\" trong danh sach.\n", ma);
    }
}

// Hàm tìm kiếm sản phẩm theo danh mục
void timKiemSanPhamTheoDanhMuc(AD sp[], int n, char danhMuc[]) {
    int timThay = 0; // Biến kiểm tra xem có sản phẩm nào thỏa mãn không
    for (int i = 0; i < n; i++) {
        if (strstr(sp[i].danhMuc, danhMuc)) {
            inThongTinSanPham(sp[i]);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("\nKhong co danh muc \"%s\" trong danh sach.\n", danhMuc);
    }
}