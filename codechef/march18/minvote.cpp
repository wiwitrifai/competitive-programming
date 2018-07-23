#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n;
long long bit[N];

long long get(int x) {
  long long r = 0;
  for (; x; x -= x&-x)
    r += bit[x];
  return r;
}
void upd(int x, int v) {
  for (; x <= n; x += x&-x)
    bit[x] += v;
}
long long sum[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
      bit[i] = 0;
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      sum[i+1] = sum[i] + a[i];
    }
    for (int i = 0; i < n; ++i) {
      int l = i+1, r = n-1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (sum[mid] - sum[i+1] <= a[i])
          l = mid;
        else
          r = mid-1;
      }
      upd(i+2, +1);
      upd(l+2, -1);
      l = 0, r = i-1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (sum[i] - sum[mid+1] <= a[i])
          r = mid;
        else
          l = mid+1;
      }
      upd(l+1, +1);
      upd(i+1, -1);
    }
    for (int i = 1; i <= n; ++i)
      printf("%lld%c", get(i), i == n ? '\n' : ' ');
  }
  return 0;
}