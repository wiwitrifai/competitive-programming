#include <bits/stdc++.h>

using namespace std;

const int N = 1<<16;

int val[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  int nn = 1<<n;
  while(q--) {
    int t, x;
    char s[20];
    scanf("%d", &t);
    if (t != 3)
      scanf("%d", &x);
    scanf("%s", s);
    int now = 0;
    for (int i = 0; i < n; i++) {
      now = (now << 1) | (s[i] == '1');
    }
    if (t == 1) {
      val[now] = x;
      for (int i = (now - 1) & now; i != now; i = (i-1) & now) {
        val[i] = x;
      }
    }
    else if (t == 2) {
      val[now] ^= x;
      for (int i = (now - 1) & now; i != now; i = (i-1) & now) {
        val[i] ^= x;
      }
    }
    else {
      printf("%d\n", val[now]);
    }
  }


  return 0;
}