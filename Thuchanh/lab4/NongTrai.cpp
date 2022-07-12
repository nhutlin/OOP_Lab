#include <iostream>
#define MAX 100
using namespace std;
static int SuaBo = 10;
static int SuaCuu = 5;
static int SuaDe = 8;

class GiaSuc {
    private:
    public:
        void Keu();
        int ChoSua();
};

void GiaSuc::Keu()
{
    return;
}

int ChoSua()
{
    return 0;
}

class Bo:public GiaSuc {
    private: 
        int sl;
    public:
        void Keu();
        int ChoSua();
};

void Bo::Keu()
{
    cout << "Booo,";
}
int Bo::ChoSua()
{
    return SuaBo;
}

class Cuu:public GiaSuc {
    public:
    void Keu();
    int ChoSua();
};

void Cuu::Keu() {
    cout << "Beee,";
}

int Cuu::ChoSua() 
{
    return SuaCuu;
}

class De:public GiaSuc {
    public:
        void Keu();
        int ChoSua();
};

void De::Keu() 
{
    cout << "Eeee,";
}

int De::ChoSua()
{
    return SuaDe;
}

int main(){
    int nBo, nCuu, nDe, n;
    Bo b[MAX], bo;
    Cuu c[MAX], cuu;
    De d[MAX], de;
    cin >> nBo >> nCuu >> nDe >> n;
    for(int i = 0; i < nBo; i++) 
        b[i].Keu();
    
    for(int i = 0; i < nCuu; i++) 
        c[i].Keu();
    
    for(int i = 0; i < nDe - 1; i++) 
        d[i].Keu();
    
    cout << "Eeee" << endl;
    
    cout << "Bo: " << n * nBo * bo.ChoSua() << endl;
    
    cout << "Cuu: "<< n * nCuu * cuu.ChoSua() << endl;

    cout << "De: " << n * nDe * de.ChoSua();

    return 0;
}