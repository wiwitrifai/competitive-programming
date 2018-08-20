#include <bits/stdc++.h>

using namespace std;

const int N = 707;

struct DSU {
  int p[N];
  bitset<N> bs[N];
  DSU() {
    memset(p, -1, sizeof p);
    for (int i = 0; i < N; ++i) {
      bs[i].reset();
      bs[i][i] = 1;
    }
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (-p[u] < -p[v])
      swap(u, v);
    p[u] += p[v];
    bs[u] |= bs[v];
    p[v] = u;
  }
  bitset<N> & can(int pos) {
    return bs[find(pos)];
  }
};

int dpleft[N][N], dpright[N][N];
int a[N];
bool good[N][N];

int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
      good[i][j] = good[j][i] = gcd(a[i], a[j]) > 1;
  DSU left, right;
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      int l = i, r = i+len-1;
      if (left.can(l)[r]) {
        dpleft[l][r] = 1;
        if (r+1 < n && good[l][r+1])
          right.can(r+1)[l]= 1;
        left.merge(l, r);
      }
      if (right.can(r)[l]) {
        dpright[l][r] = 1;
        if (l-1 >= 0 && good[l-1][r])
          left.can(l-1)[r] = 1;
        right.merge(r, l);
      }
    }
  }
  for (int i = 0; i < n; ++i)
    if (dpright[0][i] && dpleft[i][n-1]) {
      puts("Yes");
      return 0;
    }
  puts("No"); 
  return 0;
}