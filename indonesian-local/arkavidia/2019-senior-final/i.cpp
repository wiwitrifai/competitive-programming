#include <bits/stdc++.h>

using namespace std;

const int N = 202;

int ada[N], awal[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    memset(awal, 0, sizeof awal);
    for (int i = 0; i < m; ++i) {
      int x;
      scanf("%d", &x);
      --x;
      awal[x] = 1;
    }
    int pos = 0;
    long long best = 1e18;
    for (int x = 0; x < n; ++x) {
      for (int i = 0; i < n; ++i)
        ada[i] = awal[i];
      int now = x;
      int cnt = m;
      long long time = 0;
      while (cnt > 0) {
        if (ada[now]) {
          ada[now] = 0;
          now = (now + p) % n;
          --cnt;
          time += p;
        }
        else {
          ++now;
          if (now == n) now = 0;
          ++time;
        }
      }
      if (best > time) {
        best = time;
        pos = x;
      }
    }
    printf("%d %lld\n", pos+1, best);
  }
  return 0;
}