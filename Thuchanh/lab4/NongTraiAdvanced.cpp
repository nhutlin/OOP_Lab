#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class GiaSuc {
    protected:
        int nBo, nCuu, nDe, nTho, luot;
        int SuaBo = 0, SuaCuu = 0, SuaDe = 0;
    public:
        void Nhap();
        void Xuat();
};

void GiaSuc::Nhap()
{
    cin >> nBo >> nCuu >> nDe >> nTho >> luot;
}
void GiaSuc::Xuat()
{
    for (int i = 0; i < nBo; i++) {
        cout << "Booo,";
    }
    for (int i = 0; i < nCuu; i++) {
        cout << "Beee,";
    }
    for (int i = 0; i < nDe; i++) {
        cout << "Eeee,";
    }
    for (int i = 0; i < nTho; i++) {
        if (i != nTho - 1)
            cout << ",";
    }
    cout << endl;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int SumBo = nBo;
    int SumCuu = nCuu;
    int SumDe = nDe;
    int SumTho = nTho;
    int BoCon[100];
    int CuuCon[100];
    int DeCon[100];
    int ThoCon[100];
    for (int i = 0; i < luot; i++) {
        BoCon[i] = nBo / 2;
        if (i >= 4) {
            nBo += BoCon[count1];
            count1++;
        }
        SumBo += nBo / 2;
        SuaBo += nBo * 10 ; 
        CuuCon[i] = nCuu / 2;
        if (i >= 4) {
            nCuu += CuuCon[count2];
            count2++;
        }
        SumCuu += nCuu / 2;
        SuaCuu += nCuu * 5 ;
        DeCon[i ] = nDe / 2;
        if (i >= 4) {
            nDe += DeCon[count3];
            count3++;
        }
        SumDe += nDe / 2;
        SuaDe += nDe * 8 ;
        ThoCon[i] = nTho / 2;
        if (i >= 2) {
            nTho += ThoCon[count4];
            count4++;
        }
        SumTho += nTho / 2;
        
    }
    cout << "Bo: " << SumBo << "," << SuaBo << endl;
    cout << "Cuu: " << SumCuu << "," << SuaCuu << endl;
    cout << "De: " << SumDe << "," << SuaDe << endl;
    cout << "Tho: " << SumTho + 1 << "," << 0;
}
int main() {
    GiaSuc gs;
    gs.Nhap();
    gs.Xuat();
    return 0;
}
