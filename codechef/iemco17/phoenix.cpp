#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int h[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ok = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d", h+i);
      if (i && h[i] != h[i-1])
        ok = 0;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", r+i);
      if (r[i] < 15)
        ok = 0;
    }
    puts(ok ? "Party" : "No Party");
  }
  return 0;
}