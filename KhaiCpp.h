#pragma once
#include "HeaderCpp.h"
#include "DuongCpp.h"
bool MatKhauAdmin();
void menuAdmin();
void DSSP :: timKiemSanPhamTheoTen(const string _ten) {
	    int timThay = 0; 
	    for (int i = 0; i < n; i++) {
	    	string s=data[i].getName();
	        if (s.find(_ten)!=string::npos ) {
	            cout<<data[i];
	            timThay = 1;
	        }
	    }
	    if (!timThay) {
	        cout<<"\nKhong co san pham nao co ten "<<_ten<<" trong danh sach.\n";
	    }
}
	//Ham tim kiem san pham theo ma
void DSSP :: timKiemSanPhamTheoMa(const string _ma) {
	    int timThay = 0;
	    for (int i = 0; i < n; i++) {
	    	string s=data[i].getID();
	        if (s.find(_ma)!=string::npos) {
	            cout<<data[i];
	            timThay = 1;
	        }
	    }
	    if (!timThay) {
	        cout<<"\nKhong co san pham nao co ma "<<_ma<<" trong danh sach.\n";
	    }
}
		//tim kiem theo danh muc
void DSSP :: timKiemSanPhamTheoDanhMuc(const string _danhMuc ){
	    int timThay = 0;
	    for (int i = 0; i < n; i++) {
	    	string s=data[i].getDanhMuc();
	        if (s.find(_danhMuc)!= string::npos) {
	            cout<<data[i];
	            timThay = 1;
	        }
	    }
	    if (!timThay) {
	        cout<<"\nKhong co san pham nao co ma "<<_danhMuc<<" trong danh sach.\n";
	    }
}
void DSSP :: sapXepTheoGiaBan() {
	    for (int i = 0; i < n - 1; i++) {
	        for (int j = i + 1; j < n; j++) {
	            if (data[i].get_giaBan() > data[j].get_giaBan()) {
	                SanPham temp = data[i];
	                data[i] = data[j];
	                data[j] = temp;
	            }
	        }
	    }
	    for (int i=0; i<n ;i++)
	    	cout<<data[i];
}
void DSSP :: sapXepTheoGiaNhap() {
	    for (int i = 0; i < n - 1; i++) {
	        for (int j = i + 1; j < n; j++) {
	            if (data[i].get_giaNhap() > data[j].get_giaNhap()) {
	                SanPham temp = data[i];
	                data[i] = data[j];
	                data[j] = temp;
	            }
	        }
	    }
	    for (int i=0; i<n ;i++)
	    	cout<<data[i];
}
bool MatKhauAdmin(){
	string pass,check;
	cout<<"Nhap mat khau:";
	cin>>pass;
	ifstream ifs("MATKHAUAD.txt");
	getline(ifs,check);
	ifs.close();
	if (pass==check) return true;
	else {
		cout<<"Mat khau sai."<<endl;
		return false;
	}
}
void menuAdmin(){
	int choose;
	do {
		ifstream ifs("DS_SANPHAM.txt");
		DSSP sp;
		ifs>>sp;
        cout << "\n================================================";
        cout << "\n======================MENU======================";
        cout << "\n1. Nhap them san pham:  ";
        cout << "\n2. Xuat danh sach san pham: ";
        cout << "\n3. Tim kiem san pham theo ten ";
        cout << "\n4. Tim kiem san pham theo ma ";
        cout << "\n5. Tim kiem san pham theo danh muc ";
        cout << "\n6. Xoa san pham tu danh sach";
        cout << "\n7. Loi nhuan thu duoc cua tung san pham ";
        cout << "\n8. Sap xep danh sach san pham theo gia ban ";
        cout << "\n9. Sap xep danh sach san pham theo gia nhap ";
        cout << "\n10. Nhap so luong san pham ban ra. ";
        cout << "\n0. Thoat ";
        cout << "\n================================================";
        cout << "\n";
        cout << "\nNhap lua chon cua ban: ";
        cin >> choose;
		switch (choose) {
            case 1: {
            	int add;
            	cout<<"Nhap so luong san pham muon them: ";
				cin>>add;
            	sp.ThemSP(add);
            	ofstream ofs("DS_SANPHAM.txt");
				ofs<<sp;
				ofs.close();
				break;
            }
            case 2: {
            	cout<<sp;
            	//for (int i=0; i<n; i++) cout<<sp[i];
                break;
            }
            case 3:{
            	string _ten;
            	cout<<"Nhap ten san pham can tim: ";
            	cin>>_ten;
            	cout<<setw(5)<<left<<"Ma"<<"\t";
				cout<<setw(15)<<left<<"Ten san pham"<<"\t";
				cout<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
				cout<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
				cout<<setw(25)<<left<<"Ngay san xuat"<<"\t";
				cout<<setw(25)<<left<<"Han su dung"<<"\t";
				cout<<setw(15)<<left<<"Danh Muc"<<endl;
            	sp.timKiemSanPhamTheoTen(_ten);
				break;
			}
			case 4:{
				string _ma;
            	cout<<"Nhap ma san pham can tim: ";
            	cin>>_ma;
            	cout<<setw(5)<<left<<"Ma"<<"\t";
				cout<<setw(15)<<left<<"Ten san pham"<<"\t";
				cout<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
				cout<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
				cout<<setw(25)<<left<<"Ngay san xuat"<<"\t";
				cout<<setw(25)<<left<<"Han su dung"<<"\t";
				cout<<setw(15)<<left<<"Danh Muc"<<endl;
            	sp.timKiemSanPhamTheoMa(_ma);
				break;
			}
			case 5:{
				string _danhMuc;
            	cout<<"Nhap danh muc san pham can tim: ";
            	cin>>_danhMuc;
            	cout<<setw(5)<<left<<"Ma"<<"\t";
				cout<<setw(15)<<left<<"Ten san pham"<<"\t";
				cout<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
				cout<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
				cout<<setw(25)<<left<<"Ngay san xuat"<<"\t";
				cout<<setw(25)<<left<<"Han su dung"<<"\t";
				cout<<setw(15)<<left<<"Danh Muc"<<endl;
            	sp.timKiemSanPhamTheoDanhMuc(_danhMuc);
				break;
			}
			case 6:{
				int del;
				cout<<"Nhap so thu tu san pham muon xoa: ";
				cin>>del;
            	sp.XoaSP(del);
            	ifstream ifs("DS_SANPHAM.txt");
				DSSP sp;
				ifs>>sp;
				ifs.close();
				break;
			}
			case 7:{
				sp.LaiTungSP();
				break;
			}
			case 8:{
				cout<<setw(5)<<left<<"Ma"<<"\t";
				cout<<setw(15)<<left<<"Ten san pham"<<"\t";
				cout<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
				cout<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
				cout<<setw(25)<<left<<"Ngay san xuat"<<"\t";
				cout<<setw(25)<<left<<"Han su dung"<<"\t";
				cout<<setw(15)<<left<<"Danh Muc"<<endl;
				sp.sapXepTheoGiaBan();				
				break;
			}
			case 9:{
				cout<<setw(5)<<left<<"Ma"<<"\t";
				cout<<setw(15)<<left<<"Ten san pham"<<"\t";
				cout<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
				cout<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
				cout<<setw(25)<<left<<"Ngay san xuat"<<"\t";
				cout<<setw(25)<<left<<"Han su dung"<<"\t";
				cout<<setw(15)<<left<<"Danh Muc"<<endl;
				sp.sapXepTheoGiaNhap();
				break;
			}
			case 10:{
				sp.NhapSoLuongBan();
				break;
			}
            case 0:{
				cout << "Thoat chuong trinh."<<endl;
                break;
			}    
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
    	}
    	ifs.close();
    } while (choose != 0);  
	
}
