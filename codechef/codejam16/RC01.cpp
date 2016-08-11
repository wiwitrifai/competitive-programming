#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N], x[N][N], b[N];

int main() {
  int n, q;
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i), b[i] = a[i];
  sort(b, b+n);
  int m = unique(b, b+n)-b;
  for(int i = 0; i<m; i++) {
    int sum = 0;
    x[i][0] = 0;
    for(int j = 0; j<n; j++) {
      if(a[j] == b[i])
        sum++;
      x[i][j+1] = sum + (i ? x[i-1][j+1] : 0);
    }
  }
  scanf("%d", &q);
  while(q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int lo, hi;
    lo = 0, hi = m-1;
    int mm = (r-l+1)/2;
    while(lo < hi) {
      int mid = (lo + hi) >> 1;
      if(x[mid][r]-x[mid][l] >= mm)
        hi = mid;
      else
        lo = mid+1;
    }
    printf("%d\n", b[lo]);
  }


  return 0;
}