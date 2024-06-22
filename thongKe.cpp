#include <iostream>
#include <string>
using namespace std;

class order{                 
	/*...........*/
    /*bien dem so luong san pham khach hang mua (int s)*/
    /*bien dem so tien ban ra ung voi 1 san pham khach hang mua (double p)*/
    /*bien dem so tien nhap 1 san pham ve (double a)*/
	static int countSP;               //thong ke tong so luong san pham ban ra nam trong class san pham
    static double sum, stonk;              //tong so tien thu ve
public: 
	order(/*....*/){               //ham tao dem so luong san pham ban ra va so tien thu vao
        /*........*/
        countSP += s;
        sum += p * s;
        stonk += s * (p - a);
    };

    ~order(){                        //ham huy don da tao
        countSP -= s;
        sum -= p * s;
        stonk -= s * (p - a);
    }

    static void thongKe(){
        cout<<"Tong san pham da ban ra la " << countSP << endl;
		cout<<"Tong so tien nhan ve la " << sum << endl;
        cout<<"So tien lai la " << stonk << endl;
    }
};

int order::countSP = 0;
double order::sum = 0, order::stonk = 0;