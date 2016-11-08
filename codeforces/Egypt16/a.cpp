#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("powers.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
      int b, c;
      scanf("%d %d", &b, &c);
      if (b & 1)
        ans ^= c & 1;
      else {
        c %= b+1;
        if (c == b)
          ans ^= 2;
        else
          ans ^= c & 1;
      }
    }
    puts(ans ? "1" : "2"); 
  }
  return 0;
}