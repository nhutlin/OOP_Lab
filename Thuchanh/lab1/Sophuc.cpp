#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Sophuc {
private:
    float thuc;
    float ao;
public:
    Sophuc()
    {
        thuc = 0;
        ao = 0;
    }
    ~Sophuc()
    {
        thuc = 0;
        ao = 0;
    }
    void Nhap()
    {
        cin >> thuc;
        cin >> ao;
    }
    float Module()
    {
        float kq = pow(this->thuc, 2) + pow(this->ao, 2);
        if (sqrt(kq) == 0) {
            cout << "ERROR";
            exit(0);
        }
        return kq;
    }
    void Xuat()
    {
        if (thuc == 0) {
            if (ao == -1) cout << " -i";
            else if (ao == 1) cout << " i";
            else if (ao == 0) cout << 0;
            else cout << ao << "i";
        }
        else {
            if (ao == -1) cout << thuc << " - i";
            else if (ao == 1) cout << thuc << " + i";
            else if (ao == 0) cout << thuc;
            else if (ao > 0) cout << thuc << " + " << ao << "i";
            else cout << thuc << " - " << abs(ao) << "i";
        }
    }
    Sophuc Tong(Sophuc x)
    {
        Sophuc y;
        y.thuc = this->thuc + x.thuc;
        y.ao = this->ao + x.ao;
        return y;
    }
    Sophuc Hieu(Sophuc x)
    {
        Sophuc y;
        y.thuc = this->thuc - x.thuc;
        y.ao = this->ao - x.ao;
        return y;
    }
    Sophuc Tich(Sophuc x)
    {
        Sophuc R;
        R.thuc = (this->thuc * x.thuc) - (this->ao * x.ao);
        R.ao = (this->thuc * x.ao) + (this->ao * x.thuc);
        return R;
    }
    Sophuc Tich(float x)
    {
        Sophuc y;
        y.thuc = this->thuc * x;
        y.ao = this->ao * x;
        return y;
    }
    Sophuc Thuong(Sophuc x)
    {
        Sophuc y;
        if (x.Module() != 0) {
            y.thuc = ((this->thuc * x.thuc) + (this->ao * x.ao)) / x.Module();
            y.ao = ((x.thuc * this->ao) - (this->thuc * x.ao)) / x.Module();
        }
        return y;
    }
};
int main() {
    Sophuc c1, c2;
    c1.Nhap();
    c2.Nhap();
    Sophuc n;
    n = (((c1.Tong(c2)).Tich(c2.Hieu(c1.Tich(2)))).Thuong(c1.Hieu(c2.Tich(4))));
    n.Xuat();
    return 0;
}
