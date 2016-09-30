#include <bits/stdc++.h>

using namespace std;
char s[10024], val[10024], ans[10024];

int main() {
  scanf("%s", s);
  while (s[0] != 'e') {
    if (s[0] == 'f') {
      int base = 0;
      int n = strlen(s);
      for (int i = 5; i < n; i++) {
        base = base * 10 + s[i] - '0';
      }
      base = -base;
      long long now = 0;
      scanf("%s", val);
      n = strlen(val);  
      for (int i = 0; i < n; i++) {
        now = now * base + (val[i] - '0');
      }
      cout << now << endl;
    }
    else {
      int base = 0;
      int n = strlen(s);
      for (int i = 3; i < n; i++) {
        base = base * 10 + s[i] - '0';
      }
      base = -base;
      long long now;
      scanf("%lld", &now);
      if (now == 0) {
        puts("0");
      }
      else {
        long long cur = 1;
        long long res = 0;
        if (now > 0) {
          res = -base-1;
          int cnt = 0;
          while (res < now) {
            cur *= base;
            if (cur > 0) {
              res += cur * (-base-1);
              cnt += 2;
            }
          }
          long long bb = base * base;
          
        }
        else {
          while (res > now) {
            cur *= base;
            if (cur < 0)
              res += cur * (-base-1);
          }
        }
        res = 0;
        while(cur) {
          int dig = 0;
          if (cur > 0) {
            while (res < now) {
              dig++;
              res += cur;
            }
          }
          else {
            while (res > now) {
              dig++;
              res += cur;
            }
          }
          cur /= base;
          printf("%d", dig);
        }
        assert (res == now);
        printf("\n");
      }
    }
    scanf("%s", s);
  }
  return 0;
}