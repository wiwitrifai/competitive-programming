#include <bits/stdc++.h>

using namespace std;

const int N = 51;

set<long long> to[N][N];

int a[N], b[N];

int main() {
  for (int i = N-1; i >= 0; --i) {
    for (int j = i-1; j > 0; --j) {
      int t = i % j;
    }
    to[i][i].insert(0);
    for (int j = i; j > 0; --j) {
      for (long long x : to[i][j]) {
        for (int k = j; k > 0;--k) {
          int t = j % k;
          to[i][t].insert(x | (1LL << k));
        }
      }
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
    if (to[a[i]][b[i]].empty())
      ok = 0;
    // for (long long x : to[a[i]][b[i]])
    //   cerr << a[i] << " " << b[i] << " " << x << endl;
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  long long now = (1LL << 51) - 1;
  for (int i = 50; i >= 0; --i) {
    now ^= 1LL << i;
    bool ok = 1;
    for (int j = 0; j < n; ++j) {
      ok = 0;
      for (long long x : to[a[j]][b[j]]) {
        if ((x & now) == x)
          ok = 1;
      }
      if (!ok) break;
    }
    if (!ok)
      now ^= 1LL << i;
  }
  cout << now << endl;
  return 0;
}