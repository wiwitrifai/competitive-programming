#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int main() {
  int n, k;
  scanf("%d %d", &k, &n);
  a.resize(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
  }
  while (true) {
    int s = -1, x = -1;
    int grund = 0;
    for (int i = 0; i < k; ++i) {
      grund ^= a[i] % (n+1);
    }
    for (int i = 0; i < k; ++i) {
      int cur = a[i] % (n+1);
      int val = cur ^ grund;
      int d = (cur - val) % (n + 1);
      if (d <= 0)
        d += n + 1;
      if (d <= a[i] && d <= n) {
        s = i+1;
        x = d;
      }
    }
    assert(s != -1);
    a[s-1] -= x;
    printf("%d %d\n", s, x);
    fflush(stdout);
    scanf("%d %d", &s, &x);
    if (s == -1)
      break;
    a[s-1] -= x;
  }
  return 0;
}
