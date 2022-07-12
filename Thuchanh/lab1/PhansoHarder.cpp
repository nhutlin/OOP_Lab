#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Phanso {
    int tu;
    int mau;
};
void Nhap(Phanso a[], int &n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i].tu;
        do{
            cin >> a[i].mau;
        }while(a[i].mau == 0);
    }
}
void Xuat(Phanso a) {
        cout << a.tu << "/" << a.mau;
}
double value(Phanso a) {
    return (a.tu * 1.0) / a.mau;
}
void XuatMinMax(Phanso a[], int n)  {
    int vtmax = 0;
    int vtmin = 0;
    double psmax = value(a[0]);
    double psmin = value(a[0]);
    for(int i = 0; i < n; i++) {
        if(value(a[i]) > psmax) {
            psmax = value(a[i]);
            vtmax = i;
        }
        if(value(a[i]) < psmin) {
            psmin = value(a[i]);
            vtmin = i;
        }
    }
    Xuat(a[vtmin]);
    cout << endl;
    Xuat(a[vtmax]);
}
int main() {
    Phanso a[100];
    int n;
    cin >> n;
    Nhap(a, n);
    XuatMinMax(a, n);
}