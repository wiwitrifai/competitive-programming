#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, LN = 20;

int a[N], n, d;
long long sum[N];
int st[LN][N];
bool ans[N];

void go(int l, int r) {
  int len = r-l+1, lg = 31-__builtin_clz(len);
  int le = st[lg][l], ri = st[lg][r-(1<<lg) + 1];
  int best = a[le] >= a[ri] ? le : ri;
  ans[best] = 1;
  if (l == r)
    return;
  if (l < best) {
    long long val = sum[best] - sum[l];
    if (val + d >= a[best])
      go(l, best-1);
  }
  if (best < r) {
    long long val = sum[r+1] - sum[best+1];
    if (val + d >= a[best])
      go(best+1, r);
  }
}

int main() {
  scanf("%d %d", &n, &d);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    sum[i+1] = a[i] + sum[i];
    st[0][i] = i;
  }
  for (int i = 0; i+1 < LN; i++) {
    for (int j = 0; j + (1 << (i+1)) <= n; j++) {
      int le = st[i][j], ri = st[i][j + (1 << i)];
      st[i+1][j] = a[le] >= a[ri] ? le : ri;
    }
  }
  go(0, n-1);
  for (int i = 0; i < n; i++)
    if (ans[i])
      printf("%d ", i+1);
  printf("\n");
  return 0;
}