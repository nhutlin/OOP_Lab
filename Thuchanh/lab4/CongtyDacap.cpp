#include <iostream>
#include <cstring>
using namespace std;

static int TongSanPham = 0;
static int TongNgayLam = 0;

class NhanVien {
    public: 
        string hoten;
        float Luong;
        virtual void Nhap() {
            cin >> hoten;
        }
        void Xuat() {
            cout << hoten << ": " << Luong << endl;
        }
        virtual void TinhLuong() = 0;
        
        
};

class NVSanXuat : public NhanVien {
    public: 
        float LuongCanBan;
        int SoSanPham;
        void Nhap() {
            NhanVien::Nhap();
            cin >> LuongCanBan >> SoSanPham;
            TongSanPham += SoSanPham;
        }
        void TinhLuong() {
            Luong = LuongCanBan + SoSanPham * 5;
        }
};

class NVVanPhong : public NhanVien {
    public:
        int SoNgayLam;
        void Nhap() {
            NhanVien::Nhap();
            cin >> SoNgayLam;
            TongNgayLam += SoNgayLam;
        }
        void TinhLuong() {
            Luong = SoNgayLam * 100;
        }
};

class Sep : public NhanVien {
    public:
        void TinhLuong() {
            Luong = 100 + TongSanPham * 2 + TongNgayLam * 40;
        }
};

int main() {
    int n, loai;
    cin >> n;
    NhanVien* DSNV[100];
    for(int i = 0; i < n; i++) {
        cin >> loai;
        switch(loai) {
            case 1:
                DSNV[i] = new NVSanXuat;
                break;
            case 2:
                DSNV[i] = new NVVanPhong;
                break;
            case 3:
                DSNV[i] = new Sep;
                break;
            default:
                break;
        }
        DSNV[i]->Nhap();
    }
    for(int i = 0; i < n; i++) {
        DSNV[i]->TinhLuong();
        DSNV[i]->Xuat();
    }
    return 0;
}
