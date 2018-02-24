#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k, x;
    scanf("%d %d %d %d", &n, &m, &x, &k);
    scanf("%s", s);
    int odd = 0, even = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == 'O')
        ++odd;
      else
        ++even;
    }
    int tot = 0;
    for (int i = 1; i <= m; ++i) {
      if (i & 1) {
        int d = min(x, odd);
        tot += d;
        odd -= d;
      }
      else {
        int d = min(x, even);
        tot += d;
        even -= d;        
      }
    }
    puts(tot >= n ? "yes" : "no");
  }
  return 0;
}