#include <iostream>
#include <math.h>
using namespace std;
class DonThuc{
	private:
		int heso;
		int somu;
	public:
		DonThuc();
		DonThuc(int,int);
		int getHeso();
		int getSomu();
		void setHeso(int);
		void setSomu(int);
		void NhapDonThuc();
		void XuatDonThuc(int index);
		float TinhGiaTri(float);
		DonThuc TinhDaoHam();
		DonThuc TinhTong(DonThuc);
};
class DaThuc {
	private: 
		int n;
		DonThuc *a;
	public:
		void NhapDaThuc(int &so_luong);
		void XuatDaThuc(int index);
		BacDaThuc(int max , int so_luong);
		float TinhGiaTri(int,float);
		DaThuc Cong(Dathuc);
		DaThuc Tru(Dathuc);
};
void DonThuc::setHeso(int n) {
    heso = n;
}
void DonThuc::setSomu(int m) {
    somu = m;
}
int DonThuc::getHeso() {
    return heso;
}
int DonThuc::getSomu(){
    return somu;
}
void DonThuc::NhapDonThuc(){
    cout << "\nNhap he so:\t\t";
    cin >> this -> heso;
    cout << "\nNhap so mu:\t\t";
    cin >> this -> somu;

}
void DonThuc::XuatDonThuc(int index){
    if (heso == 0) return;
    if (index == 0){
        if (somu == 0) cout << heso;
            else if (somu == 1) {
              if (heso == 1) cout << "x";
                else if (heso == -1) cout << "-x";
                    else cout << heso << "x";  
        } 
        else {
            if (heso == 1) cout << "x^" << somu;
                else if (heso == -1) cout << "-x^" << somu;
                    else cout << heso << "x^" << somu; 
        }  
    } 
    else if (index != 0) {
        if (somu == 0) {
            if (heso < 0) cout << " - " << fabs(heso);
            
            else if (heso > 0) cout << " + " << heso;
        }

        else if (somu == 1) {
            if (heso == 1) cout << " + " << "x";

            else if (heso == -1) cout << " - " << "x";

            else if (heso < 0) cout << " - " << fabs(heso) << "x";
            
            else if(heso > 0) cout << " + " << heso << "x";   
        }

        else {
            if(heso == 1) cout << " + " << "x^" << somu;

            else if (heso == -1) cout << " - " << "x^" << somu;

            else if (heso < 0) cout << " - " << fabs(heso) << "x^" << somu;

            else if(heso > 0) cout << " + " << heso << "x^" << somu;
        }
    }
}
float TinhGiaTri(float){

}
void DaThuc::NhapDaThuc(int &n)
{
    do {
        cout << "Nhap so luong don thuc:\t";
        cin >> n;
    } while (n > 50 || n <= 0);

    for (int i = 0; i < n; i++) {
        NhapDonThuc(a[i]);
    }
}
int DaThuc::BacDaThuc(int max, int n)
{
    max = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i].somu > max) && (a[i].heso != 0)) max = a[i].somu;
    }
    return max;
}