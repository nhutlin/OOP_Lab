#include <iostream>
using namespace std;
class DonThuc {
    private:
        int heso;
    public:
        DonThuc() {
            heso = 0;
        }
        void NhapDonThuc() {
            cin >> heso;
        }
        void XuatDonThuc(int pos) {
            if (heso == 0) return;
            if (pos == 0) {
                cout << heso << "x^" << pos;
            }
            else {
                if (heso < 0) cout << heso << "x^" << pos;
                else cout << "+" << heso << "x^" << pos;
            }
        }
        friend class DaThuc;
};
class DaThuc {
    private:
        DonThuc *aHS;
        int Bac;
    public:
        DaThuc() {
            aHS = new DonThuc[Bac];
            Bac = -1;
        }
        DaThuc(int &nBac) {
            Bac = nBac;
            aHS = new DonThuc[nBac + 1];
        }

        void NhapDaThuc() {
            do {
                cin >> Bac;
            } while (Bac < 0);
            aHS = new DonThuc[Bac + 1];
            for (int i = 0; i <= Bac; i++) {
                aHS[i].NhapDonThuc();
            }
        }
        void XuatDaThuc() {
            for (int i = 0; i <= Bac; i++) {
                aHS[i].XuatDonThuc(i);
            }
        }
        DaThuc* Cong(DaThuc *d2) {
            if (d2 -> Bac >= Bac) swap(*d2, *this);
            for (int i = 0; i <= Bac; i++) {
                if (i > d2 -> Bac) d2 -> aHS[i].heso = 0;
                aHS[i].heso += d2 -> aHS[i].heso;
            }
            return this;
        }
        DaThuc* Tru(DaThuc *d2) {
            int max = (Bac > d2->Bac) ? Bac : d2->Bac;
            int min = (Bac < d2->Bac) ? Bac : d2->Bac;
            for (int i = 0; i <= min; i++) {
                aHS[i].heso = aHS[i].heso - d2->aHS[i].heso;
            }
            if (Bac == max) {
                for (int i = min + 1; i <= max; i++) {
                    aHS[i].heso = aHS[i].heso;
                }
            } else {
                for (int i = min + 1; i <= max; i++) {
                    aHS[i].heso = 0 - d2->aHS[i].heso;
                }
            }
            Bac = max;
            return this;
        }
        DaThuc* Nhan(DaThuc *d2) {
            int *a = new int[Bac + d2->Bac + 1];
            for (int i = 0; i < Bac + d2->Bac + 1; i++) {
                a[i] = 0;
            }
            for (int i = 0; i <= Bac; i++) {
                for (int j = 0; j <= d2->Bac; j++) {
                    a[i + j] += (aHS[i].heso * d2->aHS[j].heso);
                }
            }
            int nBac = Bac + d2->Bac;
            DaThuc *p = new DaThuc(nBac);
            for (int i = 0; i < Bac +d2->Bac + 1; i++) {
                p->aHS[i].heso = a[i];
            }
            return p;
        }
};
int main()
{
    DaThuc *d1 = new DaThuc;
    DaThuc *d2 = new DaThuc;
    DaThuc *p = new DaThuc;
    d1->NhapDaThuc();
    d2->NhapDaThuc();
    int n;
    do
    {
        cin >> n;
    } while (n < 1 || n > 3);
    
    switch (n) {
        case 1:
            d1 = d1->Cong(d2);
            d1->XuatDaThuc();
            break;
        case 2:
            d1 = d1->Tru(d2);
            d1->XuatDaThuc();
            break;
        case 3:
            p = d1->Nhan(d2);
            p->XuatDaThuc();
            break;
    }
    return 0;
}