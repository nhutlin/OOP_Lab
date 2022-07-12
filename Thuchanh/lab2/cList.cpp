#include <iostream>
using namespace std;
#define MAX 101
class list {
    private:
        double *p = new double[MAX];
        int size = 0;
    public:
        void Xuat() {
            cout << "[";
            for(int i = 0; i < size; i++) {
                cout << p[i];
                if(i != (size - 1)) cout << ",";
            }
            cout << "]";
        }
        void Add() {
            double x;
            cin >> x;
            p[size] = x;
            size++;
        }
        void deleteHead() {
            double x;
            cin >> x;
            for(int i = 0; i < size; i++) {
                if(p[i] == x) {
                    for(int j = i; j < size - 1; j++)
                        p[j] = p[j + 1];
                    size--;
                    break; 
                }
            }
        }
        void deleteAll() {
            double x;
            cin >> x;
            for (int i = 0; i < size; i++) {
                if(p[i] == x) {
                    for(int j = i; j < size - 1; j++)
                        p[j] = p[j + 1];
                    size--;
                }
            }
        }
        void Change() {
            int a;
            double b;
            cin >> a >> b;
            if((a > - 1) &&(a < size)) {
                p[a] = b; 
            }
        }
        void process() {
            int n;
            while(n != -1) {
                cin >> n;
                switch(n) {
                    case -1:
                        Xuat();
                        break;
                    case 1:
                        deleteHead();
                        break;
                    case 2:
                        deleteAll();
                        break; 
                    case 3:
                        Change();
                        break;
                    case 0:
                        Add();
                        break;
                    default: 
                        break; 
            } 

        }
    }
};
int main() {
    list a;
    a.process();
    return 0;
}