#include <iostream>
#include <string>
#include <fstream>
using namespace std;

fstream f;
istream in;

class cus{       //class khach hang
	string name, sdt, pass;
	int count;     //dem so san pham da mua
public:
	cus(string n = "A", string s = "A", string p = "A", int c = 0){            //ham tao
		name = n;
		sdt = s;
		pass = p;
		count = c;
	}
	string getName()const{ return name;}
    void addName(string n){
        name = n;
    }
	string getTel()const{ return sdt;}
    void addTel(string n){
        sdt = n;
    }
	string getPass()const{ return pass;}
    void addPass(string n){
        pass = n;
    }
	void signup(cus& a){          //ham dang ky cho khach hang
		cin>> a;
		f.open("ttcus.txt", ios::app);
		f<< a.name << endl;
		f<< a.sdt << endl;
		f<< a.pass << endl;
		f.close();
		cout<< a;
	}
	void login(cus& a){           //ham dang nhap cho khach hang
		string user, mk;
		cin.ignore();
		cout<<"Nhap so dien thoai: ";
		getline(cin, user);
		cout<<"Nhap mat khau: ";
		getline(cin, mk);
	}

	void menu(cus& a){			//menu khach hang
		int i = 0;
        while(1){
			cout<<"1. Xem thong tin khach hang." << endl;
			cout<<"2. Chinh sua thong tin tai khoan." << endl;  
            cout<<"3. Mua hang." << endl;
			cout<<"An phim tuong ung voi chuc nang:" << endl;
			cin>> i; 
			if(i == 1){
				cout<< a;
			}
			if(i == 2){
				edit(a);
			}
			if(i == 3){
				                                      //chuyen den trang mua hang
			}
		}
	}

	void edit(cus& a){         		//ham chinh sua thong tin (them vao menu cho cua khach hang sau khi dang nhap) 
		int j = 0;
        string n = "A";
		char confirm = 'K';
		do{
			cout<<"1. Doi ten." << endl;
			cout<<"2. Doi so dien thoai." << endl;    
			cout<<"3. Doi mat khau." << endl;
			cout<<"An phim tuong ung voi chuc nang:" << endl;
			cin>> j;
			if(j == 1){
				cout<<"Nhap ten moi: ";
				getline(cin, n);
				addName(n);
				f.open("ttcus.txt", ios::app);
				f<< n << endl;
				f.close();
			}
			if(j == 2){
				cout<<"Nhap so dien thoai moi: ";
				getline(cin, n);
				addTel(n);
				f.open("ttcus.txt", ios::app);
				f<< n << endl;
				f.close();
			}
			if(j == 3){
				cout<<"Nhap mat khau moi: ";
				getline(cin, n);
				addPass(n);
				f.open("ttcus.txt", ios::app);
				f<< n << endl;
				f.close();
			}
			cout<<"Quy khach muon tiep tuc chinh sua thong tin khong? C/K";
			cin>> confirm;
		}
		while(confirm == 'C' || confirm == 'c');
	}

	friend class order;
	friend ostream& operator<<(ostream& os, const cus& a);      // ham dang ky thong tin
	friend istream& operator>>(istream& is, cus& a);            //ham hien thong tin khach hang
};

ostream& operator<<(ostream& os, const cus& a){
	os << "Ten: " << a.getName << "\n";
	os << "So dien thoai: " << a.getTel << "\n";
	os << "Mat khau: " << a.getPass << "\n";
	os << "San pham da mua: " << a.count << "\n";
	return os;
}

istream& operator>>(istream& is, cus& a){
	cout<<"Nhap ten cua quy khach: ";
	getline(is, a.name);
	cout<<"Nhap so dien thoai cua quy khach: ";                                       // loai bo ky tu enter con thua
	getline(is, a.sdt);
	cout<<"Nhap mat khau cua quy khach: ";
	getline(is, a.pass);
	return is;
}

int main(){
	cus A;
	A.signup(A);
}
