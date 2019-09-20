#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N][N], all[N], ans[N];

int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    all[i] = 0;
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i]+j);
      all[i] = gcd(all[i], a[i][j]);
    }
  }
  vector<int> cand;
  for (int i = 1; 1LL * i * i <= all[0]; ++i) {
    if (all[0] % i) continue;
    cand.push_back(i);
    if (i * i != all[0])
      cand.push_back(all[0] / i);
  }
  for (int x : cand) {
    ans[0] = x;
    for (int i = 1; i < n; ++i)
      ans[i] = a[0][i] / x;
    bool ok = 1;
    for (int i = 0; ok && i < n; ++i) {
      for (int j = i+1; ok && j < n; ++j) {
        if (1LL * ans[i] * ans[j] != a[i][j]) {
          ok = 0;
        }
      }
    }
    if (ok) {
      for (int i = 0; i < n; ++i) {
        printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
      }
      return 0;
    }
  }
  return 0;
}
