#include <iostream>
using namespace std;
#include <cstring>
class Donthuc {
    private:
        int heso;
    public:
        Donthuc() {
            heso = 0;
        }
    void NhapDonthuc();
    void XuatDonthuc(int, int);
    friend class Dathuc;
};
void Donthuc::NhapDonthuc() {
    cin >> heso;
}
void Donthuc::XuatDonthuc(int pos, int bac) {
    if(heso == 0) return;
    if(pos == 0) cout << heso << "x^" << bac;
    else {
        if(heso < 0) cout << heso << "x^" << bac;
        else cout << "+" << heso << "x^" << bac;
    }
}
class Dathuc {
    private:
        Donthuc  *aHeSo;
        int bac;
    public:
        Dathuc();
        Dathuc(int &nbac);
        void NhapDathuc();
        void XuatDathuc();
        Dathuc* operator+(Dathuc*);
        Dathuc* operator-(Dathuc*);
        Dathuc* operator*(Dathuc*);
        Dathuc* operator*(int x);
};
Dathuc::Dathuc() {
    aHeSo = new Donthuc[bac];
    bac = -1;
}
Dathuc::Dathuc(int &nbac) {
    bac = nbac;
    aHeSo = new Donthuc[nbac + 1];
}
void Dathuc::NhapDathuc() {
    do {
        cin >> bac;
    }while(bac < 0);
    aHeSo = new Donthuc[bac + 1];
    for(int i = 0; i <= bac; i++)
        aHeSo[i].NhapDonthuc();
}
void Dathuc::XuatDathuc() {
    int nbac = 0;
    for(int i = 0; i <= bac; i++) {
        aHeSo[i].XuatDonthuc(i, nbac);
        nbac++;
    }
}
Dathuc* Dathuc::operator+(Dathuc* d2) {
    if(d2->bac >= bac) swap(*d2, *this);
    for(int i = 0; i <= bac; i++) {
        if(i > d2->bac) d2->aHeSo[i].heso = 0;
        aHeSo[i].heso += d2->aHeSo[i].heso;
    }
    return this;
}
Dathuc* Dathuc::operator-(Dathuc *d2) {
    int max = (bac > d2->bac) ? bac : d2->bac;
    int min = (bac < d2->bac) ? bac : d2->bac;
    for(int i = 0; i <= min; i++)
        aHeSo[i].heso = aHeSo[i].heso - d2->aHeSo[i].heso;
    if(bac == max) {
        for(int i = min; i <= max; i++)
            aHeSo[i].heso = 0 - d2->aHeSo[i].heso;
    }
    else {
        for(int i = min; i <= max; i++) 
        aHeSo[i].heso = 0 - d2->aHeSo[i].heso;
    }
    bac = max;
    return this;
}
Dathuc* Dathuc::operator*(Dathuc* d2) {
    int *a = new int[bac + d2->bac + 1];
    for(int i = 0; i < bac + d2->bac + 1; i++) a[i] = 0;
    for(int i = 0; i <= bac; i++) {
        for(int j = 0; j <= d2->bac; i++) {
            a[i + j] += (aHeSo[i].heso * d2->aHeSo[j].heso);
        }
    }
    int nbac = bac + d2->bac;
    Dathuc *p = new Dathuc(nbac);
    for(int i = 0; i < bac + d2->bac + 1; i++) {
        p->aHeSo[i].heso = a[i];
    }
    return p;
}
int main() {
    Dathuc *d1 = new Dathuc;
    Dathuc *d2 = new Dathuc;
    Dathuc *p = new Dathuc;
    d1->NhapDathuc();
    d2->NhapDathuc();
    string chuoi;
    cin >> chuoi;
    if(chuoi == "+") p = *d1 + d2;
    else if(chuoi == "-") p = *d1 - d2;
    else if(chuoi == "*") p = *d1 * d2;
    p->XuatDathuc();
    return 0;
}