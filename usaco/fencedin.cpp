#include <bits/stdc++.h>

using namespace std;

const int N =25123;

int A, B, n, m;
int a[N], b[N];

int main() {
  freopen("fencedin.in", "r", stdin);
  freopen("fencedin.out", "w", stdout);
  scanf("%d%d", &A, &B);
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) 
    scanf("%d", a+i);
  for(int i = 0; i<m; i++)
    scanf("%d", b+i);
  int now = 0;
  sort(a, a+n);
  sort(b, b+m);
  for(int i = 0; i<n; i++) {
    a[i] -= now;
    now += a[i];
  }
  a[n] = A-now;
  now = 0;
  for(int i = 0; i<m; i++) {
    b[i] -= now;
    now += b[i];
  }
  b[m] = B-now;
  n++; m++;
  sort(a, a+n);
  sort(b, b+m);
  int na, nb;
  na = nb = 0;
  long long ans = 0;
  while(na < n || nb < m) {
    // cout << na << " " << nb << endl;
    if((a[na] < b[nb] && na < n) || nb == m) {
      if(na == 0) {
        ans += 1LL*a[na] * (m-1);
        // cnt += m-1;
      }
      else {
        ans += 1LL*a[na] * min(m - nb, m - 1);
        // cnt += min(m - nb, m - 1);
      }
      na++;
    }
    else {
      if(nb == 0) {
        ans += 1LL*b[nb]*(n-1);
        // cnt += n-1;
      }
      else {
        ans += 1LL*b[nb] * min(n - na, n-1);
        // cnt += min(n - na, n - 1);
      }
      nb++;
    }
  }
  printf("%lld\n", ans);
  fclose(stdin);
  fclose(stdout); 
  return 0;
}