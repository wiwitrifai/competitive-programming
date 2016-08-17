#include <bits/stdc++.h>

using namespace std;

const int N = 505;

bitset< N > g[N], ans[N], temp[N];
int k[N], n;

bitset< N > process(bitset< N > a) {
  bitset< N > ret;
  ret.reset();
  for(int i = 0; i<n; i++)
    if(a[i])
      ret = ret | g[i];
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++) {
      int x;
      scanf("%d", &x);
      g[i][j] = x;
    }
  int m;
  scanf("%d", &m);
  int mk = 0;
  for(int i = 0; i<m; i++) {
    int x;
    scanf("%d%d", k+i, &x);
    ans[i].reset();
    ans[i][x-1] = 1;
    mk = max(mk, k[i]);
  }
  for(int mask = 1; mask < mk; mask <<= 1) {
    for(int i = 0; i<m; i++) if(k[i] & mask) {
      ans[i] = process(ans[i]);
    }
    for(int i = 0; i<n; i++) {
      temp[i] = process(g[i]);
    }
    for(int i = 0; i<n; i++) {
      g[i] = temp[i];
    }
  }
  for(int i = 0; i<m; i++) {
    int cnt = ans[i].count();
    printf("%d\n", cnt);
    if(cnt == 0) {
      printf("-1");
    }
    else {
      for(int j = 0; j<n; j++)
        if(ans[i][j])
          printf("%d ", j+1);
    }
    printf("\n");
  }
  return 0;
}