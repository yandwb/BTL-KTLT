#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
//lop Date
class Date{
	int ngay;
    int thang;
    int nam;
public:
	Date(){
		ngay=0;
		thang=0;
		nam=0;
	}
	friend istream& operator>>( istream& is,Date& d){
		is>>d.ngay>>d.thang>>d.nam;
		return is;
	}
	friend ostream& operator<<( ostream& os,const Date& d){
		os<<d.ngay<<"/"<<d.thang<<"/"<<d.nam;
		return os;
	}
	friend ifstream& operator>>( ifstream& ifs,Date& d){
		ifs>>d.ngay;
		ifs.ignore();
		ifs>>d.thang;
		ifs.ignore();
		ifs>>d.nam;
	}
	friend ofstream& operator<<( ofstream& ofs,const Date& d){
		ofs<<d.ngay<<"/"<<d.thang<<"/"<<d.nam;
	}
	void get_date(int& _ngay, int& _thang , int& _nam){
		_ngay=ngay;
		_thang=thang;
		_nam=nam;
	}
	void set_ngay(int _ngay){
		ngay=_ngay;
	}
	void set_thang(int _thang){
		thang=_thang;
	}
	void set_nam(int _nam){
		nam=_nam;
	}
};
//lop san pham
class SanPham{
	string ma;
    string ten;
    double giaNhap;
    double giaBan;
    Date ngaySX;
    Date hanSD;
    int soLuongBan, soLuongNhap;
    string danhMuc;
    double tongThu, tongNhap;
public:
	friend class Date;
	//ham tao
	SanPham(string _ma="a",string _ten="a", double _giaNhap=0,double _giaBan=0, Date _ngaySX=Date(), Date _hanSD=Date(), int _soLuongBan=0, int _soLuongNhap=0, string _danhMuc="a", double _tongThu=0, double _tongNhap=0){
		ma=_ma;
		ten=_ten;
		giaNhap=_giaNhap;
		giaBan=_giaBan;
		ngaySX=_ngaySX;
		hanSD=_hanSD;
		soLuongBan=_soLuongBan;
		soLuongNhap=_soLuongNhap;
		danhMuc=_danhMuc;
		tongThu=_tongThu;
		tongNhap=_tongNhap;
	}
	
	//ham nhap san pham
	friend istream& operator>>( istream& is,SanPham& sp){
		cout<<"Nhap thong tin san pham: "<<endl;
		cout<<"\nNhap ma san pham: ";
		is.ignore(); 
		getline(is,sp.ma);
		cout<<"Nhap ten san pham: ";
		getline(is,sp.ten);
		cout<<"Nhap gia nhap san pham: ";
		is>>sp.giaNhap;
		cout<<"Nhap gia ban san pham: ";
		is>>sp.giaBan;
		cout<<"Nhap ngay san xuat: ";
		is>>sp.ngaySX;
		cout<<"Nhap han su dung: ";
		is>>sp.hanSD;
		is.ignore();
		cout<<"Nhap danh muc san pham:";
		getline(is,sp.danhMuc);
		/*cout<<"Nhap so luong nhap vao san pham: ";
		is>>sp.soLuongNhap;*/
		return is;
	}
	//ham xuat san pham
	friend ostream& operator<<( ostream& os, const SanPham& sp){
		os<<setw(5)<<left<<sp.ma<<"\t";
		os<<setw(15)<<left<<sp.ten<<"\t";
		os<<setw(20)<<left<<sp.giaNhap<<"\t";
		os<<setw(20)<<left<<sp.giaBan<<"\t";
		os<<sp.ngaySX<<setw(18)<<left<<"\t";
		os<<sp.hanSD<<setw(18)<<left<<"\t";
		os<<setw(15)<<left<<sp.danhMuc;
		return os;
	}	
	friend ofstream& operator<<(ofstream& ofs, const SanPham& sp){
			ofs<<sp.ma<<","<<sp.ten<<","<<sp.giaNhap<<","<<sp.giaBan<<","<<sp.ngaySX<<","<<sp.hanSD<<","<<sp.danhMuc<<"."<<endl;
			return ofs;
	}
	
	friend ifstream& operator>>(ifstream& ifs, SanPham& sp) {
	    getline(ifs, sp.ma, ',');
	    getline(ifs, sp.ten, ',');
	    ifs >> sp.giaNhap;
	    ifs.ignore();  
	    ifs >> sp.giaBan;
	    ifs.ignore(); 
	    ifs >> sp.ngaySX;
	    ifs.ignore(); 
	    ifs >> sp.hanSD;
	    ifs.ignore(); 
	    getline(ifs, sp.danhMuc, '.');
	    return ifs;
	}
	
	string getName(){
		return ten;
	}
	string getID(){
		return ma;
	}
	string getDanhMuc(){
		return danhMuc;
	}
	void set_soLuongBan(int _soLuongBan){
		soLuongBan=_soLuongBan;
	}
	int get_soLuongBan(){
		return soLuongBan;
	}
	double get_giaNhap(){
		return giaNhap;
	}
	double get_giaBan(){
		return giaBan;
	}
	void set_soLuongNhap(int _soLuongNhap){
		soLuongNhap=_soLuongNhap;
	}
	//friend class DSSP;
};
//lop danh sach san pham
class DSSP{
	int n;
	SanPham* data;
public:
	DSSP(int _n=0, SanPham _d=SanPham()){
		n=_n;
		data = new SanPham[n];
		for (int i=0; i<n ;i++)
			data[i]=_d;
	}
	//ham nhap danh sach san pham
	friend istream& operator>>(istream& is,DSSP& ds){
		cout<<"Nhap so luong san pham: ";
		is>>ds.n;
		ds.data= new SanPham[ds.n];
		for (int i=0;i<ds.n;i++)
		{
			cout<<"\nNhap thong tin san pham thu "<<i+1<<endl;
				is>>ds.data[i];
		}
		return is;
	}
	//ham xuat danh sach san pham
	friend ostream& operator<<( ostream& os, const DSSP& ds){
		os<<setw(5)<<left<<"Ma"<<"\t";
		os<<setw(15)<<left<<"Ten san pham"<<"\t";
		os<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
		os<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
		os<<setw(20)<<left<<"Ngay san xuat"<<"\t";
		os<<setw(20)<<left<<"Han su dung"<<"\t";
		os<<setw(15)<<left<<"Danh Muc"<<endl;
		for (int i=0;i<ds.n;i++)
			os<<ds.data[i]<<endl;
		return os;
	}
	//ghi danh sach san pham vao file
	friend ofstream& operator<<(ofstream& ofs, const DSSP& ds){
		ofs<<ds.n<<endl;
		for (int i=0;i<ds.n;i++)
			ofs<<ds.data[i];
	}
	//doc danh sach san pham tu file
	friend ifstream& operator>>(ifstream& ifs, DSSP& ds){
		ifs>>ds.n;
		ds.data= new SanPham[ds.n];
		for (int i=0;i<ds.n;i++)
			ifs>>ds.data[i];
	}
	void ThemSP(int add){
		int d;
		n+=add;
		data = new SanPham[n];
		ifstream ifs("DS_SANPHAM.txt");
		ifs>>d;
		for (int i=0;i<d;i++) ifs>>data[i];
		for (int i=d ;i<n;i++) 
		{
			cin>>data[i];
		}
		ifs.close();
	}
	void XoaSP(int del){
		ofstream ofs("DS_SANPHAM.txt");
		ofs.clear();
		ofs<<n-1;
		for (int i=0;i<del-1;i++) ofs<<data[i];
		for (int i=del;i<n;i++) ofs<<data[i];
		ofs.close();
	}
	virtual ~DSSP() {
        delete[] data;
    }
    friend class SanPham;
    void timKiemSanPhamTheoTen(const string _ten) {
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
	//Hàm tìm ki?m s?n ph?m theo mã
	void timKiemSanPhamTheoMa(const string _ma) {
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
	void timKiemSanPhamTheoDanhMuc(const string _danhMuc ){
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
    //Nhap so luong san pham ban ra
  	void NhapSoLuongBan(){
  		for (int i=0;i<n;i++)
  		{	
  			int _soLuongBan;
  			cout<<"Nhap so luong ban ra cua san pham "<<data[i].getName() <<" ";
  			cin>>_soLuongBan;
  			data[i].set_soLuongBan(_soLuongBan);
  		}
	  }

	double TongLaiThuDuoc(){
		double _tongThu=0;
		for (int i=0;i<n;i++)
		{
		_tongThu+=(data[i].get_soLuongBan())*(data[i].get_giaBan()-data[i].get_giaNhap());
		}
		return _tongThu;
	}
	void sapXepTheoGiaBan() {
	    for (int i = 0; i < n - 1; i++) {
	        for (int j = i + 1; j < n; j++) {
	            if (data[i].get_giaBan() > data[j].get_giaBan()) {
	                SanPham temp = data[i];
	                data[i] = data[j];
	                data[j] = temp;
	            }
	        }
	    }
	    cout<<setw(5)<<left<<"Ma"<<"\t";
		cout<<setw(15)<<left<<"Ten san pham"<<"\t";
		cout<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
		cout<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
		cout<<setw(20)<<left<<"Ngay san xuat"<<"\t";
		cout<<setw(20)<<left<<"Han su dung"<<"\t";
		cout<<setw(15)<<left<<"Danh Muc"<<endl;
	    for (int i=0; i<n ;i++)
	    	cout<<data[i];
	}
	void sapXepTheoGiaNhap() {
	    for (int i = 0; i < n - 1; i++) {
	        for (int j = i + 1; j < n; j++) {
	            if (data[i].get_giaNhap() > data[j].get_giaNhap()) {
	                SanPham temp = data[i];
	                data[i] = data[j];
	                data[j] = temp;
	            }
	        }
	    }
	    cout<<setw(5)<<left<<"Ma"<<"\t";
		cout<<setw(15)<<left<<"Ten san pham"<<"\t";
		cout<<setw(20)<<left<<"Gia nhap san pham(VND)"<<"\t";
		cout<<setw(20)<<left<<"Gia ban san pham(VND)"<<"\t";
		cout<<setw(20)<<left<<"Ngay san xuat"<<"\t";
		cout<<setw(20)<<left<<"Han su dung"<<"\t";
		cout<<setw(15)<<left<<"Danh Muc"<<endl;
	    for (int i=0; i<n ;i++)
	    	cout<<data[i];
	}
};

int main(){
	
	/*int n;
	ifs>>n;
	ifs.ignore();
    //cout<<"\nNhap so luong san pham: ";
    SanPham* sp=new SanPham[n];
    for (int i=0;i<n;i++) ifs>>sp[i];  */  
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
        cout << "\n7. Loi nhuan thu duoc ";
        cout << "\n8. Sap xep danh sach san pham theo gia ban ";
        cout << "\n9. Sap xep danh sach san pham theo gia nhap ";
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
            	sp.timKiemSanPhamTheoTen(_ten);
				break;
			}
			case 4:{
				string _ma;
            	cout<<"Nhap ma san pham can tim: ";
            	cin>>_ma;
            	sp.timKiemSanPhamTheoMa(_ma);
				break;
			}
			case 5:{
				string _danhMuc;
            	cout<<"Nhap danh muc san pham can tim: ";
            	cin>>_danhMuc;
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
				sp.NhapSoLuongBan();
				cout<<"Loi nhuan: "<<sp.TongLaiThuDuoc()<<" (VND)";
				break;
			}
			case 8:{
				sp.sapXepTheoGiaBan();				
				break;
			}
			case 9:{
				sp.sapXepTheoGiaNhap();
				break;
			}
		
            case 0:{
				cout << "Thoat chuong trinh.";
                break;
			}    
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
    	}
    	ifs.close();
    } while (choose != 0);  
}
