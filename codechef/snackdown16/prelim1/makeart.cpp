#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    int ma, now, x, cnt;
    ma = now = cnt = 0;
    scanf("%d", &n);
    while(n--) {
      scanf("%d", &x);
      if(x == now)
        cnt++;
      else {
        now = x;
        cnt = 1;
      }
      ma = max(ma, cnt);
    }
    puts(ma >= 3 ? "Yes" : "No");
  }

  return 0;
}