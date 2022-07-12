#include <iostream>
using namespace std;
class Quaternion {
    private:
        int a, b, c, d;
    public:
        Quaternion operator+(Quaternion);
        Quaternion operator-(Quaternion);
        friend ostream& operator<<(ostream&, Quaternion);
        friend istream& operator>>(istream&, Quaternion&);
};

ostream& operator<<(ostream& os, Quaternion x)
{
    os << "(" << x.a << "," << x.b << "," << x.c << "," << x.d << ")";
    return os;
}

istream& operator>>(istream& is, Quaternion &y)
{
    is >> y.a >> y.b >> y.c >> y.d;
    return is;
}

Quaternion Quaternion::operator+(Quaternion n)
{
    Quaternion k;
    k.a = a + n.a;
    k.b = b + n.b;
    k.c = c + n.c;
    k.d = d + n.d;
    return k;
}

Quaternion Quaternion::operator-(Quaternion n)
{
    Quaternion k;
    k.a = a - n.a;
    k.b = b - n.b;
    k.c = c - n.c;
    k.d = d - n.d;
    return k;
}

int main() {
    Quaternion a, b;
    cin >> a >> b;
    cout << a + b;
    cout << endl;
    cout << a - b;
    system("pause");
    return 0;
}