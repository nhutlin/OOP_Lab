#include <iostream>
using namespace std;
#define PI 3.14

static float dientich = 0;
static float thetich = 0;

class Chai {
    public:
        virtual void Nhap() = 0;
        // void Xuat() {
        //     cout << "Dien tich chai vo: " << dientich << endl;
        //     cout << "Luong nuoc tren mat dat: " << thetich << endl;
        // }
        virtual void TinhDienTich() = 0;
        virtual void TinhTheTich() = 0;

};

class TruTron:public Chai {
    float height = 0;
    float radius = 0;
    public: 
        void Nhap();
        void TinhDienTich();
        void TinhTheTich(); 
};

class Hop:public Chai {
    float height = 0;
    float length = 0;
    float width = 0;
    public:
        void Nhap();
        void TinhDienTich(); 
        void TinhTheTich(); 
};

class LapPhuong:public Chai {
    float a;
    public:
        void Nhap();
        void TinhTheTich();
        void TinhDienTich(); 
};

void TruTron::Nhap() 
{
    cin >> height >> radius;
}

void TruTron::TinhDienTich()
{
    dientich += PI * height * 2 * radius;
}

void TruTron::TinhTheTich() 
{
    thetich += PI * radius * radius * height * 0.1;
}

void Hop::Nhap() 
{
    cin >> height >> length >> width;
}

void Hop::TinhDienTich() 
{
    dientich += 2 * height * (length + width) + 2 * length * width;
}

void Hop::TinhTheTich() 
{
    thetich += height * length * width * 0.1;
}

void LapPhuong::Nhap()
{
    cin >> a;
}

void LapPhuong::TinhDienTich()
{
    dientich += a * a * 6;
}

void LapPhuong::TinhTheTich() 
{
    thetich += a * a * a * 0.1;
}

int main() {
    int n, loai;
    cin >> n;
    Chai* DSChai[100];
    for(int i = 0; i < n; i++) {
        cin >> loai;
        switch(loai) {
            case 1:
                DSChai[i] = new TruTron;
                break;
            case 2:
                DSChai[i] = new Hop;
                break;
            case 3:
                DSChai[i] = new LapPhuong;
                break;
            default:
                break;
        }
        DSChai[i]->Nhap();
    }
    for(int i = 0; i < n; i++) {
        DSChai[i]->TinhDienTich();
        DSChai[i]->TinhTheTich();
    }
    cout << "Dien tich chai vo: " << dientich << endl;
    cout << "Luong nuoc tren mat dat: " << thetich << endl;

    return 0;
}