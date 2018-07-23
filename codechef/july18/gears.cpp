#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N], col[N];
int a[N];
int work[N];
int find(int x) {
  if (p[x] < 0)
    return x;
  int root = find(p[x]);
  work[x] &= work[p[x]];
  col[x] ^= col[p[x]];
  p[x] = root;
  return root;
}

long long gcd(long long x, long long y) {
  return x ? gcd(y % x, x) : y;
}

int main() {
  int n, m;
  scanf("%d %d", &n,&m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  memset(p, -1, sizeof p);
  memset(work, 1, sizeof work);
  while (m--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    --x;
    if (t == 1) {
      a[x] = y;
    }
    else if (t == 2) {
      --y;
      int u = find(x), v = find(y);
      if (u == v) {
        if (col[x] == col[y]) {
          work[u] = 0;
        }
      }
      else {
        if (-p[u] < -p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
        if (col[x] == col[y])
          col[v] ^= 1;
      }
    }
    else {
      int s;
      scanf("%d", &s);
      --y;
      int u = find(x), v = find(y);
      if (u != v || !work[u]) {
        puts("0");
      }
      else {
        long long up = a[x] * 1LL * s, down = a[y];
        long long g = gcd(up, down);
        up /= g;
        down /= g;
        if (col[x] == col[y]) {
          printf("%lld/%lld\n", up, down);
        }
        else {
          printf("-%lld/%lld\n",up, down);
        }
      }
    }
  }
  return 0;
}