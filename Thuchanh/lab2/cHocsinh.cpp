#include <iostream>
using namespace std;
class Student {
    private:
    string name;
    float diemtoan, diemvan, dtb;
    public:
    void Nhap();
    void Xuat();

};
int main() {
    Student a;
    a.Nhap();
    a.Xuat();

}
void Student::Nhap() {
    getline(cin, this->name);
    do {
    cin >> diemtoan >> diemvan;
    }while (diemtoan < 10 || diemtoan > 0 || diemvan < 10 || diemvan > 0);
    dtb = float((diemtoan + diemvan) / 2.0);
}
void Student::Xuat() {
    cout << "Thong tin hoc sinh:" << endl;
    cout << "Ho ten: " << name << endl;
    cout << "Diem toan: " << diemtoan << endl;
    cout << "Diem van: " << diemvan << endl;
    cout << "Diem trung binh: " << dtb;
}