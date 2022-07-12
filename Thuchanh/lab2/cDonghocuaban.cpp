#include <iostream>
#include <cmath>
using namespace std;
class Time {
    private:
        int hour;
        int min;
        int sec;
    public:
        Time(){
            hour = min = sec = 0;
        }
        void set();
        void Up1s();
        void Down1s();
        void Upxs();
        void Downxs();
        void Output();
        void Chuanhoa();

};
int main() {
    Time a;
    a.set();
    int n;
    do {
        cin >> n;
        switch(n) {
            case 1:
                a.Up1s();
                break;
            case 2:
                a.Down1s();
                break;
            case 3:
                a.Upxs();
                break;
            case 4:
                a.Downxs();
                break;
            case -1:
                a.Output();
                exit(0);
                break;
        }
    }while(1);
    return 0;
}
void Time::set() {
    cin >> hour >> min >> sec;
    Chuanhoa();
}
void Time::Up1s() {
    sec = abs(sec);
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
            sec = 0;
            min++;
        }
    } 

    else {
        sec++;
    }
}
void Time::Down1s() {
    sec = abs(sec);
    if(sec == 0) {
        if(min == 0) {
            if(hour == 0) {
                hour = 23;
                min = sec = 59;
            }
            else {
                hour--;
                min = sec = 59;
            }
        }
        else {
            sec = 59;
            min--;
        }
    }
    else {
        sec--;
    }
}
void Time::Upxs()
{
    int x;
    cin >> x;
    sec = sec + x;
    Chuanhoa();

}
void Time::Downxs() {
    int x;
    cin >> x;
    sec = sec - x;
    min = min - 1 + (sec / 60);
    sec = 60 + (sec % 60);
    Chuanhoa();
}
void Time::Output() {
    cout << hour << "h " << min << "p " << sec << "s ";
}
void Time::Chuanhoa() {
    hour = abs(hour);
    min = abs(min);
    sec = abs(sec);
    if(sec >= 60) {
        min += sec / 60;
        sec %= 60;
    }
    if(min >= 60) {
        hour += min / 60;
        min %= 60;
    }
    if(hour >= 24) {
        hour %= 24;
    }
}
