#include <iostream>
using namespace std;
int Namnhuan(int y)
{
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}
int Dayofmonth(int m, int y) {
  switch(m) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    {
      return 31;
    }
    case 2: 
    {
      if (Namnhuan(y)) return 29;
      return 28;
    }
    case 4: case 6: case 9: case 11:
    {
      return 30;
    }   
  }
}
void Thedayafter(int y, int m, int d) {
  int nexty = y; 
  int nextm = m;
  int nextd = d;
  if(y > 0 && m > 0 && m < 13 && d > 0 && d <= (Dayofmonth(m, y))) {
    nextd = d + 1;
  if(m != 12 && d == Dayofmonth(m, y)) {
    nextd = 1;
    nextm = m + 1;
  }
  else if(m == 12 && d == Dayofmonth(m,y)) {
    nextd = 1;
    nexty = y + 1;
    nextm = 1;
  }
  else if(m == 2) {
    if(Namnhuan(y)) {
      if(d == 29) {
        nextd = 1;
        nextm = m + 1;
      }
    }
      else {
        if(d == 28) {
          nextd = 1 ;
          nextm = m + 1;
        }
      }
    }     
  }
    cout << nextd << "/" << nextm << "/" << nexty;
}
int main() {
  int y, m, d;
  cin >> d;
  cin >> m;
  cin >> y;
  if(y < 0 || m < 1 || m >12 || d < 0 || d > 31) {
      cout << "ERROR";
  }
  else {
  Thedayafter(y, m, d);
  }
  return 0;
}
