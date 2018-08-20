#include <bits/stdc++.h>

using namespace std;

const int N = 1505;

int p[N];
bitset<N> bs[N];
bool g[N][N];
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}
int a[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int n;
void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  bs[u] |= bs[v];
  p[v] = u;
}

int le[N][N];
int ri[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  fill(p, p+2*n, -1);
  for (int i = 0; i < n; ++i) {
    bs[i].reset();
    bs[i][i] = 1;
    bs[i+n].reset();
    bs[i+n][i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    g[i][i] = 1;
    for (int  j = i+1; j < n; ++j) {
      g[i][j] = g[j][i] = gcd(a[i], a[j]) > 1;
    }
  }
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      int l = i, r = i+len-1;
      if (bs[find(l)][r]) {
        le[l][r] = 1;
        if (r+1 < n && g[l][r+1]) {
          bs[find(r+1+n)][l] = 1;
        }
        merge(l, r);
      }
      if (bs[find(r+n)][l]) {
        ri[l][r] = 1;
        if (l-1 >= 0 && g[l-1][r]) {
          bs[find(l-1)][r] = 1;
        }
        merge(l+n, r+n);
      }
    }
  }
  bool ok = 0;
  for (int i = 0; i < n; ++i) {
    if (ri[0][i] && le[i][n-1]) {
      ok = 1;
    }
  }
  puts(ok ? "Yes" : "No");
  return 0;
}