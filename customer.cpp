#include <iostream>
#include <string>
using namespace std;

class cus{       //class khach hang
	string name, sdt, mail, pass;
	int count;     //dem so san pham da mua
public:
	cus(string n = "A", string s = "A", string m = "A", string p = "A", int c = 0){            //ham tao
		name = n;
		sdt = s;
		mail = m;
		pass = p;
		count = c;
	}
	void signup(cus& a){          //ham dang ky cho khach hang
		cin>> a;
		cout<< a;
	}
	void login(){           //ham dang nhap cho khach hang
		string user, mk;
		cout<<"Nhap email hoac so dien thoai: ";
		getline(cin, user);
		cout<<"Nhap mat khau: ";
		getline(cin, mk);
		if(){                     //neu thong tin dang nhap dung

		}
	}

	void menu(cus& a){			//menu khach hang
		while(1){
			cout<<"1. Xem thong tin khach hang." << endl;
			cout<<"2. Chinh sua thong tin tai khoan." << endl;  
			cout<<"An phim tuong ung voi chuc nang:" << endl;
			cin>> i; 
		}
	}

	void edit(cus& a){         		//ham chinh sua thong tin (them vao menu cho cua khach hang sau khi dang nhap) 
		int j = 0;
		cout<<"1. Doi ten." << endl;
		cout<<"2. Doi email." << endl;  
		cout<<"3. Doi email." << endl;  
		cout<<"4. Doi mat khau." << endl;
		cout<<"An phim tuong ung voi chuc nang:" << endl;
		cin>> j;
		if
	}

	friend class order;
	friend ostream& operator<<(ostream& os, const cus& a);      // ham dang ky thong tin
	friend istream& operator>>(istream& is, cus& a);            //ham hien thong tin khach hang
};

class order{                 //thong ke so luong don hang nam trong class san pham
	/*...........*/
	int count;
public: 
	order(/*....*/);
};

ostream& operator<<(ostream& os, const cus& a){
	os << "Ten: " << a.name << "\n";
	os << "So dien thoai: " << a.sdt << "\n";
	os << "Email: " << a.mail << "\n";
	os << "Mat khau: " << a.pass << "\n";
	os << "San pham da mua: " << a.count << "\n";
	return os;
}

istream& operator>>(istream& is, cus& a){
	cout<<"Nhap ten cua quy khach: ";
	getline(cin, a.name);
	cout<<"Nhap so dien thoai cua quy khach: ";                                       // loai bo ky tu enter con thua
	getline(cin, a.sdt);
	cout<<"Nhap mail cua quy khach: ";
	getline(cin, a.mail);
	cout<<"Nhap mat khau cua quy khach: ";
	getline(cin, a.pass);
	return is;
}

int main(){
	cus A;
	A.signup(A);
}
