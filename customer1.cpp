#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class cus{       //class khach hang
	string sdt;
	float bonus;         //khuyen mai
public:
	cus(string s = "", float b = 0){            //ham tao
		sdt = s;
		bonus = b;
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
        cout << "Thong tin khach hang da duoc luu tru." << endl;
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

	void menu(cus& a){			//menu cho khach quen
		int i = 0;
        while(true){
			cout<<"1. Xem thong tin khach hang." << endl;
			cout<<"2. Chinh sua so dien thoai." << endl;  
			cout<<"An phim tuong ung voi chuc nang:" << endl;
			cin>> i; 
			cin.ignore();
			if(i == 1)
				cout<< a;
			if(i == 2){
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
		}
	}

	friend class order;
	friend ostream& operator<<(ostream& os, const cus& a);      // ham dang ky thong tin
	friend istream& operator>>(istream& is, cus& a);            //ham hien thong tin khach hang
};

ostream& operator<<(ostream& os, const cus& a){
	os << "So dien thoai: " << a.sdt << "\n";
	os << "Khuyen mai tich luy: " << a.bonus << "\n";
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
