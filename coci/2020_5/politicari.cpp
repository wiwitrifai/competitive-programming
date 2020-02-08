#include <bits/stdc++.h>

using namespace std;

int n;
int enc(int u, int v) {
  return u * n + v;
}

int main() {
  long long k;
  scanf("%d %lld", &n, &k);
  vector<int> go(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      scanf("%d", &x);
      --x;
      go[enc(j, i)] = x < 0 ? enc(j, i) : enc(i, x);
    }
  }
  --k;
  int now = enc(0, 1);
  vector<int> tmp(n * n);
  for (; k; k >>= 1) {
    if (k & 1)
      now = go[now];
    for (int i = 0; i < n * n; ++i)
      tmp[i] = go[go[i]];
    go.swap(tmp);
  }
  printf("%d\n", (now/n) + 1);
  return 0;
}
