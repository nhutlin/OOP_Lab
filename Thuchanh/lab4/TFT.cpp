#include <iostream>
using namespace std;

static int m;

class Champions {
    protected:
        int stgiam = 0;
    public: 
        virtual void Nhap() = 0;
        virtual void Xuat() = 0;
        virtual void TinhDame() = 0;
        virtual void TinhDame2() = 0;
};

class Malphite:public Champions {
    public: 
        void Nhap();
        void Xuat();
        void TinhDame();
        void TinhDame2();
};

class ChoGath:public Champions {
    public:
        void Nhap();
        void Xuat();
        void TinhDame();
        void TinhDame2();
};

class ListChamp {
    int dem1 = 0, dem2 = 0;
    int n;
    Champions* DSChamp[100];
    public:
        void Nhap();
        void Xuat();
};

void Malphite::Nhap()
{
    cin >> stgiam;
}

void Malphite::Xuat()
{
    cout << "Malphite - Sat thuong duoc giam: " << stgiam << endl;
}

void Malphite::TinhDame() 
{
    stgiam = (stgiam + 10) * 2 * m;
}

void Malphite::TinhDame2() 
{
    stgiam = stgiam * 2 * m;
}

void ChoGath::Nhap() 
{
    cin >> stgiam;
}

void ChoGath::Xuat() 
{
    cout<< "Cho'Gath - Sat thuong duoc giam: " << stgiam << endl;
}

void ChoGath::TinhDame() 
{

    stgiam = (stgiam + 10);
    int st = stgiam;
    for (int i = 1; i < m; i++) {
        st += 5;
        stgiam += st;
    }
}

void ChoGath::TinhDame2() 
{

    int st = stgiam;
    for (int i = 1; i < m; i++) {
        st += 5;
        stgiam += st;
    }
}

void ListChamp::Nhap()
{
    int loai;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> loai;
        if(loai == 1) {
            DSChamp[i] = new Malphite;
            dem1++;
        }
        else if(loai == 2) {
            DSChamp[i] = new ChoGath;
            dem2++;
        }
        DSChamp[i]->Nhap();
    }
    cin >> m;
}

void ListChamp::Xuat()
{
    for(int i = 0; i < n; i++) {
        if(dem1 >= 1 && dem2 >= 1) {
            DSChamp[i]->TinhDame();
            DSChamp[i]->Xuat();
        }
        else {
            DSChamp[i]->TinhDame2();
            DSChamp[i]->Xuat();
        }
    }
}

int main() {
    ListChamp l;
    l.Nhap();
    l.Xuat();
    return 0;
}
