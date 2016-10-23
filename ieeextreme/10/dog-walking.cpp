/**
  IEEExtreme Programming Contest 10
  Problem : Dog Walking
  Solver  : Wiwit Rifa'i
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    sort(a, a+n);
    n--;
    for (int i = 0; i < n; i++)
      b[i] = a[i+1] - a[i];
    sort(b, b+n);
    long long ans = a[n] - a[0];
    for (int i = 1; i <  k; i++)
      ans -= b[n-i];
    printf("%lld\n", ans);
  }

  return 0;
}