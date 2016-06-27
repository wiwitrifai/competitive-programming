#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    double h, s;
    cin >> h >> s;
    double hh = h*h;
    s *= 4;
    if(hh < s) {
      puts("-1");
      continue;
    }
    double a = (sqrt(hh + s) + sqrt(hh-s))/2;
    double b = (sqrt(hh + s) - sqrt(hh-s))/2;
    if(a < b + h && b < a + h && h < a + b && a > 0 && b > 0)
      printf("%.7lf %.7lf %.7lf\n", b, a, h);
    else
      puts("-1");
  }
  return 0;
}