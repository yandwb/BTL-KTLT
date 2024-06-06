#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SanPham {
private:
    string maSanPham;
    string tenSanPham;
    double gia;
    string ngaySanXuat;
    string hanSuDung;
    string danhMuc;

public:
    void nhapThongTinSanPham() {
        cout << "Nhap ma san pham ";
        cin >> maSanPham;
        cout << "Nhap ten san pham: ";
        cin.ignore();
        getline(cin, tenSanPham);
        cout << "Nhap gia: ";
        cin >> gia;
        cout << "Nhap ngay san xuat (dd/mm/yyyy): ";
        cin >> ngaySanXuat;
        cout << "Nhap han su dung (dd/mm/yyyy): ";
        cin >> hanSuDung;
        cout << "Nhap danh muc san pham:  ";
        cin.ignore();
        getline(cin, danhMuc);
    }

    void luuVaoTepVanBan(ofstream& outFile) {
        outFile << maSanPham << endl;
        outFile << tenSanPham << endl; 
        outFile << gia << endl;
        outFile << ngaySanXuat << endl;
        outFile << hanSuDung << endl; 
        outFile << danhMuc << endl;
    }
};

int main() {
    int soLuongSanPham;
    cout << "Nhap so luong san pham: ";
    cin >> soLuongSanPham;

    ofstream outFile("danh_sach_san_pham.txt");
    if (!outFile) {
        cout << "Khong the mo tep danh_sach_san_pham.txt" << endl;
        return 1;
    }

    for (int i = 0; i < soLuongSanPham; i++) {
        cout << "Nhap thong tin cho san pham thu: " << i + 1 << ":" << endl;
        SanPham sp;
        sp.nhapThongTinSanPham();
        sp.luuVaoTepVanBan(outFile);
    }

    outFile.close();
    cout << "Du lieu da duoc luu vao tep danh_sach_san_pham.txt" << endl;
    //Do du lieu tu file danh_sach_san_pham.txt


    return 0;
}


