#include <bits/stdc++.h>

using namespace std;

#define y1 jalfjla
#define y2 kljafja

struct Date {
  int d, m, y, w;
  Date() {
    d = 1;
    m = 1;
    y = 1900;
    w = 1;
  }
  Date(int _d, int _m, int _y) {
    d = _d;
    m = _m;
    y = _y;
    w = 1;
  }
  Date next() {
    w = (w+1) % 7;
    if(d<28)
      d++;
    else {
      switch(m) {
        case 2:
          if(y % 4 == 0 && ((y % 100 != 0) || (y % 400 == 0))) {
            if(d<29)
              d++;
            else {
              d = 1;
              m++;
            }
          }
          else {
              d = 1;
              m++;
          }
          break;

        case 4:
        case 6:
        case 9:
        case 11:
          if(d<30)
            d++;
          else {
            d = 1;
            m++;
          }
          break;
        default:
          if(d < 31)
            d++;
          else {
            if(m<12)
              d = 1, m++;
            else
              d = 1, m = 1, y++;
          }
          break;
      }
    }
    return *this;
  }
};


bool operator==(Date one, Date other) {
  return (other.d == one.d) && (other.m == one.m) && (other.y == one.y);
}
bool operator!=(Date one, Date other) {
  return (other.d != one.d) || (other.m != one.m) || (other.y != one.y);
}


int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int d1, m1, y1, d2, m2, y2;
    scanf("%d%d%d%d%d%d", &d1, &m1, &y1, &d2, &m2, &y2);
    Date now, Date1(d1, m1, y1), Date2(d2, m2, y2);
    now = Date();
    while(now != Date1) { now.next();}
    int ans = 0;
    while(true) {
      if(now.w == 5 && now.d == 13)
        ans++;
      if(now == Date2)
        break;
      now.next();
    }
    printf("%d\n", ans);
  }

  return 0;
}