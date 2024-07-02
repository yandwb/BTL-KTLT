#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class cus{       //class khach hang
	string sdt;
	float bonus;         //khuyen mai
	int count;               //so luong don hang
	SanPham *quanLy;        //quan ly san pham
public:
	SanPham proto();      //sp rong
	cus(string s = "", float b = 0, int c = 100, SanPham proto()){            //ham tao
		sdt = s;
		bonus = b;
		count = c;
		quanLy = new SanPham[n];
		for(int i = 0; i < c; i++){
			quanLy[i] = proto;
		}
	}
	~cus(){
		delete[] quanLy;
	}

	string getTel()const{ return sdt;}
    void setTel(string n=""){
        sdt = n;
    }
	float getBonus()const{ return bonus;}
    void addTel(float b){
        bonus = b;
    }
	void signup(cus& a){          //ham dang ky cho khach hang
		cout<< "*****Nhap thong tin khach hang*****" << endl;
		cin>> *this;
		ofstream f("ttcus.txt", ios::app);
        f << sdt << endl;
        f << bonus << endl << endl;
        f.close();
        cout << "Thong tin khach hang da duoc luu lai." << endl;
	}
	void login(cus& a){           //ham dang nhap cho khach hang
		string user, line;
		cin.ignore();
		cout<<"Nhap so dien thoai: ";
		getline(cin, user);
		ifstream f("ttcus.txt");

        bool found = false;         //kiem tra thong tin vua nhap
        while (getline(f, line)) 
            if (line == user) {
                found = true;
                break;
            }

        f.close();
        if (found) 
            cout << "Dang nhap thanh cong." << endl;
        else 
            cout << "So dien thoai khong ton tai." << endl;
	}

	void menuCustom(cus& a){			//menu cho khach quen
		int i = 0;
		string search, code;
        while(true){
			cout << "================================================" << endl;
        	cout << "======================MENU======================" << endl;
			cout << "1. Xem thong tin khach hang." << endl;
			cout << "2. Chinh sua so dien thoai." << endl;  
			cout << "3. Tim kiem san pham theo ten " << endl;
        	cout << "4. Tim kiem san pham theo ma " << endl;
        	cout << "5. Tim kiem san pham theo danh muc " << endl;
			cout << "================================================" << endl;
        	cout << endl << "Nhap lua chon cua ban: ";
			cin>> i; 
			cin.ignore();
			if(i == 1)
				cout<< a;
			else if(i == 2){
				string n;
				char confirm;
				do{
					confirm = 'K';
					cout<<"Nhap so dien thoai moi: ";
					getline(cin, n);
					setTel(n);
					ofstream f("ttcus.txt", ios::app);
					f << n << endl;
                    f.close();
					cout<<"Quy khach muon tiep tuc chinh sua thong tin khong? C/K";
					cin>> confirm;

				}
				while(confirm == 'C' || confirm == 'c');
			}
			else if(i == 3){
            	cout<<"Nhap ten san pham can tim: ";
            	cin>> search;
            	sp.timKiemSanPhamTheoTen(search);
				cin.ignore();
				cout<<"Nhap ma san pham ma ban muon mua: ";
				getline(cin, code);
				cout<<"Ban da mua hang thanh cong";
				a.bonus += 0.05 * //
				ofstream f("ttcus.txt");
				f << code << endl;
				f.close();
				for(int i = 0; i < count; i++){             //luu thong tin sp
					if(a.quanLy[i].compare("a") == 0)
						a.quanLy[i].ma = code;
				}
			}
			else if(i == 4){
            	cout<<"Nhap ma san pham can tim: ";
            	cin>> search;
            	sp.timKiemSanPhamTheoMa(search);
				cin.ignore();
				cout<<"Nhap ma san pham ma ban muon mua: ";
				getline(cin, code);
				cout<<"Ban da mua hang thanh cong";
				ofstream f("ttcus.txt");
				f << code << endl;
				f.close();
				for(int i = 0; i < count; i++){
					if(a.quanLy[i].compare("a") == 0)
						a.quanLy[i].ma = code;
				}
			}
			else if(i == 5){
            	cout<<"Nhap danh muc san pham can tim: ";
            	cin>> search;
            	sp.timKiemSanPhamTheoDanhMuc(search);
				cin.ignore();
				cout<<"Nhap ma san pham ma ban muon mua: ";
				getline(cin, code);
				cout<<"Ban da mua hang thanh cong";
				ofstream f("ttcus.txt");
				f << code << endl;
				f.close();
				for(int i = 0; i < count; i++){
					if(a.quanLy[i].compare("a") == 0)
						a.quanLy[i].ma = code;
				}
			}
		}
	}




	friend class DSSP;
	friend class SanPham;
	friend ostream& operator<<(ostream& os, const cus& a);      // ham dang ky thong tin
	friend istream& operator>>(istream& is, cus& a);            //ham hien thong tin khach hang
};


ostream& operator<<(ostream& os, const cus& a){
	os << "So dien thoai: " << a.sdt << "\n";
	os << "Khuyen mai tich luy: " << a.bonus << "VND\n";
	return os;
}

istream& operator>>(istream& is, cus& a){
	cout<<"Nhap so dien thoai cua quy khach: ";                                       // loai bo ky tu enter con thua
	getline(is, a.sdt);
	cin.ignore();
	return is;
}

int main(){
	cus A;
	A.signup(A);
	A.login(A);
}
