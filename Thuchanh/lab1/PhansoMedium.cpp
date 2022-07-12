#include <iostream>
#include <cmath>
using namespace std;
class PhanSo {
    int tu, mau;
};
int ucln(int a, int b) {
    if (b == 0)
        return a;
    return ucln(b, a % b);
}
void Rutgon(PhanSo &a) {
    int u = abs(ucln(a.tu, a.mau));
    if (a.tu != 0 && a.mau < 0)
        u = -u;
    a.tu /= u;
    a.mau /= u;
}
void Nhap(PhanSo &a) {
    cin >> a.tu >> a.mau;
}
void Xuat(PhanSo p) {
    cout << p.tu;
    if (abs(p.mau) != 1 && abs(p.tu) >= 0)
        cout << "/" << p.mau;
}
PhanSo Cong(PhanSo a, PhanSo b) {
    PhanSo tong;
    tong.tu = (a.tu * b.mau) + (b.tu * a.mau);
    tong.mau = a.mau * b.mau;
    Rutgon(tong);
    return tong;
}
PhanSo Tru(PhanSo a, PhanSo b){
    PhanSo tru;
    tru.tu = (a.tu * b.mau) - (b.tu * a.mau);
    tru.mau = a.mau * b.mau;
    Rutgon(tru);
    return tru;
}
PhanSo Tich(PhanSo a, PhanSo b) {
    PhanSo tich;
    tich.tu = a.tu * b.tu;
    tich.mau = a.mau * b.mau;
    Rutgon(tich);
    return tich;
}
PhanSo Thuong(PhanSo a, PhanSo b) {
    PhanSo thuong;
    thuong.tu = a.tu * b.mau;
    thuong.mau = a.mau * b.tu;
    Rutgon(thuong);
    return thuong;
}
int main() {
    PhanSo a, b;
    cout << "Nhap phan so thu 1: ";
    Nhap(a);
    cout << "Nhap phan so thu 2: ";
    Nhap(b);
    cout << "Tong cua 2 phan so la: ";
    Xuat(Cong(a, b));
    cout << endl
        << "Hieu cua 2 phan so la: ";
    Xuat(Tru(a,b));
    cout << endl
        << "Tich cua 2 phan so la: ";
    Xuat(Tich(a, b));
    cout << endl
        << "Thuong cua 2 phan so la: ";
    Xuat(Thuong(a, b));
    return 0;
}
