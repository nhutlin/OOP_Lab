#include <iostream>
#include <cstring>
using namespace std;

class Boat{
    protected:
        string num;
        int sl;
    public:
        virtual void Nhap() {
            cin >> num;
            cin >> sl;
        }
        virtual void Xuat() {
            cout << num;
        }
};

class Ghe:public Boat {
    bool dongco;
    public:
        void Nhap();
        void Xuat();
};

class Thuong:public Boat {
    string hang;
    public:
        void Nhap();
        void Xuat();
};

class Lon:public Boat {
    string hang;
    int phamvi;
    public:
        void Nhap();
        void Xuat();
};

void Ghe::Nhap()
{
    Boat::Nhap();
    cin >> dongco;
}

void Ghe::Xuat()
{
    Boat::Xuat();
    cout << " - Ghe - " << sl << " thuyen vien";
    if(dongco == 1) cout << " - Co Dong Co" << endl;
    else cout << endl;

}

void Thuong::Nhap()
{
    Boat::Nhap();
    cin >> hang;
}

void Thuong::Xuat() 
{
    Boat::Xuat();
    cout << " - Thuyen thuong - " << sl << " thuyen vien - " << hang << endl;
}

void Lon::Nhap() 
{
    Boat::Nhap();
    cin >> hang;
    cin >> phamvi;
}

void Lon::Xuat()
{
    Boat::Xuat();
    cout << " - Thuyen lon - " << sl << " thuyen vien - " << hang << " - " << phamvi << "m" << endl;
}

class DSThuyen {
    int n;
    Boat* DSBoat[100];
    public:
        void Nhap();
        void Xuat();
};

void DSThuyen::Nhap() 
{
    cin >> n;
    int loai;
    for(int i = 0; i < n; i++) {
        cin >> loai;
        if(loai == 1) DSBoat[i] = new Ghe;
        else if(loai == 2) DSBoat[i] = new Thuong;
        else if(loai == 3) DSBoat[i] = new Lon;
        DSBoat[i]->Nhap();
    }
}

void DSThuyen::Xuat()
{
    for(int i = 0; i < n; i++) {
        DSBoat[i]->Xuat();
    }
}

int main() {
    DSThuyen ds;
    ds.Nhap();
    ds.Xuat();
    return 0;
}