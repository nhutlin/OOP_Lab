#include <iostream>
using namespace std;
class MYINT {
    private:
        int num;
    public:
        MYINT(int n){
            num = n;
        }
        MYINT operator+(MYINT);
        MYINT operator*(MYINT);
        friend ostream& operator<<(ostream&, MYINT);
};

MYINT MYINT::operator+(MYINT a)
{
    return num - a.num;
}

MYINT MYINT::operator*(MYINT a)
{
    return num * a.num;
}

ostream& operator<<(ostream& os, MYINT a) 
{
    os << a.num << endl;
    return os;
}

int main() {
    MYINT a(4), b(5);
    cout << (a + b);
    cout << a * b;
    system("pause");
    return 0;
}