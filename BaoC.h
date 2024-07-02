#pragma once
#include "HeaderC.h"
#include "KietC.h"

//Hàm nhập số lượng bán ra
void nhapBan(AD sp[], int n){
    for (int i = 0; i < n ; i++){
        printf("\nNhap so luong san pham ban cho %s " ,sp[i].ten);
        scanf("%d", &sp[i].soLuongBan);
    }
}
// Hàm tính tổng các loại tiền nhập hàng và lãi
void tinhTongThu(AD sp[], int n){
    double tongThu = 0, tongNhap = 0;
    for (int i = 0; i < n; i++){
        sp[i].tongThu = sp[i].soLuongBan * sp[i].giaBan;
        sp[i].tongNhap = sp[i].soLuongBan * sp[i].giaNhap;
        tongThu = tongThu + sp[i].tongThu;
        tongNhap = tongNhap + sp[i].tongNhap;
        printf("\nSan pham %s: ", sp[i].ten);
        printf("\nTong so tien nhap hang la: %.0lf VND", tongNhap);
        printf("\nTong so tien thu la: %.0lf VND", tongThu);\
        printf("\nTong so tien lai la: %.0lf VND", tongThu - tongNhap);  
    }
    
};

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

	FILE *f;
    f = fopen("sanPham.bin", "wb");
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

// Hàm đọc danh sách sản phẩm từ file
void docDanhSachSanPhamTuFile(AD sp[], int &n){
    FILE *f;
    f = fopen("sanPham.bin", "rb");
    if (f == NULL) {
        printf("\nLoi mo file de doc!");
        return;
    }

    // Đọc số lượng sản phẩm từ file
    fread(&n, sizeof(int), 1, f);

    // Đọc từng sản phẩm và lưu vào mảng sp
    for (int i = 0; i < n; i++){
        fread(&sp[i], sizeof(AD), 1, f);
    }

    fclose(f);
}

//Hàm nhập phím bất kỳ
void nhapPhimBatKy(){
    printf("\n");
    printf("\nNhap phim bat ky de tiep tuc!");
    getch(); //Đọc kí tự từ bàn phím mà không cần nhấn enter
};  
//Hàm nhập mật khẩu cho admin
int MatKhauAdmin() {
    char pass[100], check[100];
    FILE *file;  
    printf("Nhap mat khau: ");
    scanf("%s", pass);
    
    file = fopen("MATKHAUAD.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file MATKHAUAD.txt.\n");
        return 0;
    } 
    fgets(check, sizeof(check), file);
    fclose(file);
    
    // Xóa ký tự xuống dòng ở cuối chuỗi check nếu có
    if (check[strlen(check) - 1] == '\n')
        check[strlen(check) - 1] = '\0';
    
    if (strcmp(pass, check) == 0) {
        return 1;
    } else {
        printf("Mat khau sai.\n");
        return 0;
    }
}
// Hàm thêm sản phẩm vào file
void themSanPhamVaoFile(AD sp[], int &n){
    int soLuongThem;
    printf("Nhap so luong san pham can them: ");
    scanf("%d", &soLuongThem);
    getchar(); // Đọc kí tự '\n' sau khi nhập số lượng

    FILE *f;
    f = fopen("sanPham.bin", "ab"); // Mở file để ghi thêm vào cuối file
    if (f == NULL) {
        printf("\nLoi mo file de ghi!");
        return;
    }

    for (int i = 0; i < soLuongThem; ++i) {
        AD newProduct;
        nhapThongTinSanPham(newProduct); // Nhập thông tin sản phẩm mới
        sp[n++] = newProduct; // Thêm vào mảng sản phẩm

        fwrite(&newProduct, sizeof(AD), 1, f); // Ghi thông tin sản phẩm vào file
    }
    fclose(f);
    printf("\nDa them %d san pham moi vao file.\n", soLuongThem);
}

//Hàm menu
void Menu(){
    AD sp[1000];
    int n = 0;
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
        printf("\n13. Them san pham vao ");
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
                    if (n > 0) {
                    xuatDanhSachSanPham(sp, n);
                    } else {
                    printf("\nDanh sach san pham hien tai rong.\n");
                    }
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
                    docDanhSachSanPhamTuFile(sp, n);   
                    printf("\nDa nhap danh sach san pham tu file.\n"); // Thông báo sau khi đọc xong
                    nhapPhimBatKy();
                    break;
            case 12: 
                    xuatVaoFile(sp, n);
                    nhapPhimBatKy();
                    break; 
            case 13:
                    themSanPhamVaoFile(sp, n);
                    nhapPhimBatKy();;
                    break;
        }
    } while (chon!=0);
}
