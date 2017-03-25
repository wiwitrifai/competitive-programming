#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
int root[N], L[50 * N], R[50 * N], sum[50 * N];
int rt = 1, sz = 1;
int last[N], a[N], bef[N];
 
int copy(int v, int &u) {
  L[sz] = L[v];
  R[sz] = R[v];
  sum[sz] = sum[v];
  return u = sz++;
}
 
void make_root() {
  copy(root[rt - 1], root[rt]);
  rt++;
}
 
void add(int pos, int x, int v = root[rt - 1], int l = 0, int r = N) {
  sum[v] += x;
  if(r - l < 2)
      return;
  int m = (l + r) / 2;
  if(pos < m)
      add(pos, x, copy(L[v], L[v]), l, m);
  else
      add(pos, x, copy(R[v], R[v]), m, r);
}
 
int get(int a, int b, int &ret, int v, int l = 0, int r = N) {
  if (r <= a)
      return 0;
  if (l >= a && sum[v] <= b)
    return sum[v];
  if (r-l < 2) {
    ret = l;
    return sum[v];
  }
  int m = (l + r) / 2;
  int cur = get(a, b, ret, L[v], l, m);
  if (cur > b)
    return cur;
  return cur + get(a, b-cur, ret, R[v], m, r);
}
 
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  scanf("%d", a+i);
  for (int i = n; i >= 1; i--) {
    make_root();
    add(last[a[i]], -1);
    bef[i] = last[a[i]];
    last[a[i]] = i;
    add(last[a[i]], 1);
  }
  assert(sz < 50 * N);
  int ans = n;
  for (int k = 1; k <= n; k++) {
    if (ans == 1) {
      printf("1 ");
      continue;
    }
    ans = 0;
    int l = 1;
    while (l <= n) {
      int cur = 0;
      ans++;
      int r = 0;
      if (get(l, k, r, root[n+1-l]) <= k)
        r = n+1;
      l = r;
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}