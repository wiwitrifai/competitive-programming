#include <bits/stdc++.h>

using namespace std;

long long x1, v1, x2, v2;

int main() {
  cin >> x1 >> v1 >> x2 >> v2;
  long long dx = x1 - x2;
  long long dv = v2 - v1);
  if(dx == 0) {
    puts("YES");
    return 0;
  }
  if(dv == 0) {
    puts("NO");
    return 0;
  }
  if(dv < 0) {
    dv *= -1;
    dx *= -1;
  }
  if((dx % dv) == 0 && dx/dv >= 0) {
    puts("YES");
  }
  else {
    puts("NO");
  }
  return 0;
}