#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>

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
};
//Hàm in thông tin sản phẩm
void inThongTinSanPham(AD sp){
    //chú ý giá tiền dưới dạng VNĐ
    printf("\n%5s \t %15s \t %15.0lf \t %18.0lf \t %18d/%2d/%4d \t %2d/%2d/%4d \t %10s", sp.ma, sp.ten, sp.giaNhap, sp.giaBan, sp.ngaySanXuat.ngay, sp.ngaySanXuat.thang, sp.ngaySanXuat.nam, sp.hanSuDung.ngay, sp.hanSuDung.thang, sp.hanSuDung.nam, sp.danhMuc); 
};
//Hàm cập nhật thông tin sản phẩm
void capNhatDanhSachSanPham(AD &sp){
    nhapThongTinSanPham(sp);
};
//Hàm nhập số lượng bán ra
void nhapBan(AD sp[], int n){
    for (int i = 0; i < n ; i++){
        printf("\nNhap so luong san pham ban cho %s " ,sp[i].ten);
        scanf("%d", &sp[i].soLuongBan);
    }
}
//Hàm tính tổng các loại tiền nhập hàng và lãi
void tinhTongThu(AD sp[], int n){
    double tongThu = 0, tongNhap = 0;
    for (int i = 0; i < n; i++){
        sp[i].tongThu = sp[i].soLuongBan * sp[i].giaBan;
        sp[i].tongNhap = sp[i].soLuongBan * sp[i].giaNhap;
        tongThu = tongThu + sp[i].tongThu;
        tongNhap = tongNhap + sp[i].tongNhap;
    }
    printf("\nTong so tien nhap hang la: %.0lf VND", tongNhap);
    printf("\nTong so tien thu la: %.0lf VND", tongThu);\
    printf("\nTong so tien lai la: %.0lf VND", tongThu - tongNhap);  
};
//Hàm nhập danh sách sản phẩm 
void nhapDanhSachSanPham(AD sp[], int &n){
    do{
        printf("Nhap vao so luong san pham: ");
        scanf("%d", &n);
    }while (n<=0);
    for (int i=0; i<n; i++){
        printf("\nNhap vao san pham thu %d: ", i+1);
        capNhatDanhSachSanPham(sp[i]);

    }
};
//Hàm xuất danh sách sinh viên 
void xuatDanhSachSanPham(AD sp[], int n){
    printf("\n");
    printf("\n%5s \t %15s \t %10s \t %10s \t %8s \t %8s \t %10s","Ma", "Ten san pham", "Gia nhap san pham (VND)", "Gia ban san pham (VND)","Ngay san xuat", "Han su dung", "Danh muc");
    for (int i = 0; i < n; i++){
    inThongTinSanPham(sp[i]);
    }
};
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

//Hàm sắp xếp sản phẩm theo giá bán
void sapXepTheoGiaBan(AD sp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sp[i].giaBan > sp[j].giaBan) {
                AD temp = sp[i];
                sp[i] = sp[j];
                sp[j] = temp;
            }
        }
    }
}
//Hàm sắp xếp sản phẩm theo giá nhập 
void sapXepTheoGiaNhap(AD sp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sp[i].giaNhap > sp[j].giaNhap) {
                AD temp = sp[i];
                sp[i] = sp[j];
                sp[j] = temp;
            }
        }
    }
};
//Hàm xóa sản phẩm theo mã
void xoaSanPhamTheoMa(AD sp[], int &n) {
    char maXoa[50];
    printf("Nhap ma san pham can xoa: ");
    fflush(stdin);
    fgets(maXoa, sizeof(maXoa), stdin);
    xoaXuongDong(maXoa);
    int viTriXoa = -1;
    for (int i = 0; i < n; ++i) {
        if (strcmp(sp[i].ma, maXoa) == 0) {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1) {
        for (int i = viTriXoa; i < n - 1; ++i) {
            sp[i] = sp[i + 1];
        }
        --n;
        printf("Da xoa san pham co ma: %s\n", maXoa);
    } else {
        printf("Khong tim thay san pham co ma: %s\n", maXoa);
    }
}

//Hàm xuất vào file 
void xuatVaoFile(AD sp[], int n){
	char tenFile[100];
	printf("\nNhap vao duong dan va ten file: ");
	fflush(stdin); fgets(tenFile, sizeof(tenFile), stdin); xoaXuongDong(tenFile);
	
	FILE *f;
	f = fopen(tenFile, "wb");
	if(f==NULL){
		printf("\nLoi moi file de ghi!");
		return;
	}
	fwrite(&n, sizeof(n), 1, f);
	for(int i=0; i<n; i++){
		fwrite(&sp[i], sizeof(AD), 1, f);
	}
	fclose(f);
};
//Hàm nhập từ file 
void nhapTuFile(AD sp[], int &n){
	char tenFile[100];
	printf("\nNhap vao duong dan va ten file: ");
	fflush(stdin); fgets(tenFile, sizeof(tenFile), stdin); xoaXuongDong(tenFile);
	
	FILE *f;
	f = fopen(tenFile, "rb");
	if(f==NULL){
		printf("\nLoi moi file de doc!");
		return;
	}
	fread(&n, sizeof(n), 1, f);
	for(int i=0; i<n; i++){
		fread(&sp[i], sizeof(AD), 1, f);
	}
	fclose(f);
};
//Hàm nhập phím bất kỳ
void nhapPhimBatKy(){
    printf("\n");
    printf("\nNhap phim bat ky de tiep tuc!");
    getch();
};  

int main(){
    AD sp[1000];
    int n;
    int chon;
    do{
        printf("\n================================================");
        printf("\n======================MENU======================");
        printf("\n1. Nhap danh sach san pham ");
        printf("\n2. Xuat danh sach san pham ");
        printf("\n3. Tim kiem san pham theo ten ");
        printf("\n4. Tim kiem san pham theo ma ");
        printf("\n5. Tim kiem san pham theo danh muc ");
        printf("\n6. Nhap so luong san pham ban ra ");
        printf("\n7. Tong so tien thu duoc ");
        printf("\n8. Sap xep danh sach san pham theo gia ban ");
        printf("\n9. Sap xep danh sach san pham theo gia nhap ");
        printf("\n10. Xoa san pham tu danh sach bang ma  ");
        printf("\n11. Nhap danh sach san pham tu file ");
        printf("\n12. Xuat danh sach san pham vao file ");
        printf("\n0. Thoat ");
        printf("\n================================================");
        printf("\n");
        printf("\nNhap lua chon cua ban: ");
        scanf("\n%d", &chon);

        switch(chon){
            case 1:
                    nhapDanhSachSanPham(sp, n);
                    nhapPhimBatKy();
                    break;
            case 2: 
                    xuatDanhSachSanPham(sp, n);
                    nhapPhimBatKy();
                    break;
            case 3: 
                    char tenCanTim[20];
                    printf("\nNhap ten can tim: ");
                    fflush(stdin);
                    fgets(tenCanTim, sizeof(tenCanTim), stdin);
                    xoaXuongDong(tenCanTim);
                    timKiemSanPhamTheoTen(sp, n, tenCanTim);
                    nhapPhimBatKy();
                    break;
            case 4: 
                    char maCanTim[20];
                    printf("\nNhap ma can tim: ");
                    fflush(stdin);
                    fgets(maCanTim, sizeof(maCanTim), stdin);
                    xoaXuongDong(maCanTim);
                    timKiemSanPhamTheoMa(sp, n, maCanTim);
                    nhapPhimBatKy();
                    break;
            case 5:
                    char danhMucCanTim[20];
                    printf("\nNhap danh muc can tim: ");
                    fflush(stdin);
                    fgets(danhMucCanTim, sizeof(danhMucCanTim), stdin);
                    xoaXuongDong(danhMucCanTim);
                    timKiemSanPhamTheoDanhMuc(sp, n , danhMucCanTim);
                    nhapPhimBatKy();
                    break;
            case 6: 
                    nhapBan(sp,n);
                    nhapPhimBatKy();
                    break;
            case 7:
                    tinhTongThu(sp, n);              
                    nhapPhimBatKy();
                    break;         
            case 8: 
                    sapXepTheoGiaBan(sp, n);
                    xuatDanhSachSanPham(sp, n);
                    nhapPhimBatKy();
                    break;
            case 9: 
                    sapXepTheoGiaNhap(sp, n);
                    xuatDanhSachSanPham(sp, n);
                    nhapPhimBatKy();
                    break;
            case 10:    
                    xoaSanPhamTheoMa(sp,n);
                    nhapPhimBatKy();
                    break;   
            case 11: 
                    nhapTuFile(sp, n);   
                    nhapPhimBatKy();
                    break;
            case 12: 
                    xuatVaoFile(sp, n);
                    nhapPhimBatKy();
                    break; 
        }
    } while (chon!=0);
}









