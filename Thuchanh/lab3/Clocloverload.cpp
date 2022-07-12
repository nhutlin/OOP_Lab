#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
class Time {
    private:
        int hour, min, sec, n;
    public:
        Time();
        void Nhap();
        void Chuanhoa();
        Time operator++();
        Time operator--();
        Time operator+(int up);
        Time operator-(int down);
        void luaChon();
        void Xuat();
};
int main() {
    Time dongHo;
    dongHo.Nhap();
    dongHo.luaChon();
    dongHo.Xuat();
    return 0;
}
Time::Time() {
    hour = min = sec = n = 0;
}
void Time::Nhap() {
    cin >> hour >> min >> sec;
    Chuanhoa();
}
void Time::Chuanhoa() {
    hour = abs(hour);
    min = abs(min);
    sec = abs(sec);
    if(sec >= 60) {
        min += sec / 60;
        sec = sec % 60;
    }
    if(min >= 60) {
        hour += min / 60;
        min = min % 60;
    }
    if(hour >= 24) {
        hour = hour % 24;
    }
}
Time Time::operator++() {
    if(sec == 59) {
        if(min == 59) {
            if(hour == 23) {
                hour = min = sec = 0;
            }
            else {
                min = sec = 0;
                hour++;
            }
        }
        else {
            min++;
            sec = 0;
        }
    }
    else sec++;
    return *this;
}
Time Time::operator--() {
    if(sec == 0) {
        if(min == 0) {
            if(hour == 0) {
                hour = 23;
                min = sec = 59;
            }
            else {
                min = sec = 59;
                hour--;
            }
        }
        else {
            min--;
            sec = 59;
        }
    }
    else sec--;
    return *this;
}
Time Time::operator+(int up) {
    sec += up;
    Chuanhoa();
    return *this;
}
Time Time::operator-(int down) {
    sec = sec - down;
    min = min - 1 + (sec / 60);
    sec = 60 + (sec % 60);
    Chuanhoa();
    return *this;
}
void Time::luaChon() {
    int up, down;
    cin >> n;
    string chuoi;
    for(int i = 0; i < n; i++) {
        cin >> chuoi;
        if(chuoi == "++") ++*this;
        else if(chuoi == "--") --*this;
        else if(chuoi == "+") {
            cin >> up;
            *this + up;
        }
        else if(chuoi == "-") {
            cin >> down;
            *this - down;
        }
    }
}
void Time::Xuat() {
    cout << hour << " " << min << " " << sec;
}