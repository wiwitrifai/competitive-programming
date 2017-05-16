#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], c[N], p, q, r;
long long sa[N], sb[N], sc[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  p = q = r = 0;
  for (int i = 0; i < n; i++) {
    int w, x;
    scanf("%d %d", &w, &x);
    if (w == 1)
      a[p++] = x;
    else if (w == 2)
      b[q++] = x;
    else
      c[r++] = x;
  }
  sort(a, a+p);
  sort(b, b+q);
  sort(c, c+r);
  reverse(a, a+p);
  reverse(b, b+q);
  reverse(c, c+r);
  sa[0] = 0;
  for (int i = 0; i < p; i++)
    sa[i+1] = sa[i] + a[i];
  sb[0] = 0;
  for (int i = 0; i < q; i++)
    sb[i+1] = sb[i] + b[i];
  sc[0] = 0;
  for (int i = 0; i < r; i++)
    sc[i+1] = sc[i] + c[i];
  long long ans = 0;
  for (int i = 0; i <= r; i++) {
    int sisa = m - i * 3;
    if (sisa < 0) break;
    int l = 0, r = q;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      bool ok = 1;
      if (sisa < 2 * mid)
        ok = 0;
      else {
        int satu = min(sisa - mid * 2, p);
        ok = (a[satu] + a[satu+1] <= b[mid-1]);
        ans = max(ans, sc[i] + sb[mid] + sa[satu]);
      }
      if (ok)
        l = mid;
      else
        r = mid-1;
    }
    ans = max(ans, sc[i] + sb[l] + sa[max(min(p, sisa - 2 * l), 0)]);
  }
  cout << ans << endl;
  return 0;
}