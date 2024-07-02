#pragma once
#include "HeaderCpp.h"
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
	//ghi san pham vao file
	friend ofstream& operator<<(ofstream& ofs, const SanPham& sp){
			ofs<<sp.ma<<","<<sp.ten<<","<<sp.giaNhap<<","<<sp.giaBan<<","<<sp.ngaySX<<","<<sp.hanSD<<","<<sp.danhMuc<<"."<<endl;
			return ofs;
	}
	//doc san pham tu file
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
	//Tinh tong tien lai thu duoc
	double LaiThuDuoc(){
		double _LaiThu;
		_LaiThu=soLuongBan*(giaBan-giaNhap);
		return _LaiThu;
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
	int getSoLuongSP(){
		return n;
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
		os<<setw(25)<<left<<"Ngay san xuat"<<"\t";
		os<<setw(25)<<left<<"Han su dung"<<"\t";
		os<<setw(20)<<left<<"Danh Muc"<<endl;
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
	//ham Nhap them san pham
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
	//ham Xoa San Pham
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
   
    //Nhap so luong san pham ban ra sau do luu vao file
  	void NhapSoLuongBan(){
  		ofstream ofs("SOLUONGBANRA.txt");
  		for (int i=0;i<n;i++)
  		{	
  			int _soLuongBan;
  			cout<<"Nhap so luong ban ra cua san pham "<<data[i].getName() <<" ";
  			cin>>_soLuongBan;
  			data[i].set_soLuongBan(_soLuongBan);
  			ofs<<data[i].get_soLuongBan()<<endl;
  		}
  		ofs.close();
	  }
	
	//Tinh tien lai thu duoc cua tung san pham (lay du lieu tu file)
	void LaiTungSP(){
		ifstream ifs("SOLUONGBANRA.txt");
		for (int i=0;i<n;i++)
		{	
  			int _soLuongBan;
  			ifs>>_soLuongBan;
  			cout<<"So luong ban ra cua san pham "<<data[i].getName() <<" la:"<<_soLuongBan<<endl;
  			data[i].set_soLuongBan(_soLuongBan);
			cout<<"Lai cua san pham "<<data[i].getName() <<" la:"<<data[i].LaiThuDuoc()<<endl;
		}
		ifs.close();
	}
	void timKiemSanPhamTheoTen(const string _ten);
	void timKiemSanPhamTheoMa(const string _ma);
	void timKiemSanPhamTheoDanhMuc(const string _danhMuc );
	void sapXepTheoGiaBan();
	void sapXepTheoGiaNhap();
	
};

