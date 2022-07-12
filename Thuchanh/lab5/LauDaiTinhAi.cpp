#include <iostream>
using namespace std;

class Gate {
    protected:
        int loai;
    public:
        virtual void Nhap() = 0;
        virtual int TraVe() = 0;
        int getLoai() {
            return loai;
        }
};

class Academic : public Gate {
    protected:
        int tritue;
    public:
        Academic() {
            loai = 2;
            tritue = 0;
        }
        void Nhap();
        int TraVe();
};

class Business : public Gate {
    protected:
        int dongia;
        int sohang;
    public:
        Business() {
            loai = 1;
            dongia = sohang = 0;
        }
       void Nhap();
       int TraVe(); 
};

class Power : public Gate {
    protected:
        int sucmanh;
    public:
        Power() {
            loai = 3;
            sucmanh = 0;
        }
        void Nhap();
        int TraVe();
};

void Academic::Nhap() 
{
    cin >> tritue;
}

int Academic::TraVe()
{
    return tritue;
}

void Business::Nhap()
{
    cin >> dongia >> sohang;
}

int Business::TraVe()
{
    return dongia * sohang;
}

void Power::Nhap() 
{
    cin >> sucmanh;
}

int Power::TraVe()
{
    return sucmanh;
}

class LauDaiTinhAi {
    protected:
        int n, money, knowledge, power;
        Gate* arrGate[100];
    public:
        void Nhap();
        void XetDKQuaCong();
        void Xuat();
};

void LauDaiTinhAi::Nhap() 
{
    cin >> n;
    int option;
    for(int i = 0; i < n; i++) {
        cin >> option;
        if(option == 1) arrGate[i] = new Business;
        else if(option == 2) arrGate[i] = new Academic;
        else if(option == 3) arrGate[i] = new Power;
        arrGate[i]->Nhap();
    }

    cin >> money >> knowledge >> power;
}

void LauDaiTinhAi::XetDKQuaCong() 
{
    for(int i = 0; i < n; i++) {
        if(arrGate[i]->getLoai() == 1) {
            money -= arrGate[i]->TraVe();
            if(money < 0) {
                money = -1;
                break;
            }
        }
        
        else if(arrGate[i]->getLoai() == 2) {
            if(arrGate[i]->TraVe() > knowledge) {
                knowledge = -1;
                break;
            }
        }

        else if(arrGate[i]->getLoai() == 3) {
            power -= arrGate[i]->TraVe();
            if(power < 0) {
                power = -1;
                break;
            }
        }

    }
}

void LauDaiTinhAi::Xuat()
{
    if(money == -1 || knowledge == -1 || power == -1) 
        cout << -1;
    else cout << money << " " << knowledge << " " << power;
}

int main() {
    LauDaiTinhAi dsgates;
    dsgates.Nhap();
    dsgates.XetDKQuaCong();
    dsgates.Xuat();
    return 0;
}