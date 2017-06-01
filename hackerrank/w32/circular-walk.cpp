#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 7;

int c[N];

int main() {
    int n, s, t, sr, g, seed, p;
    cin >> n >> s >> t;
    cin >> sr >> g >> seed >> p;
    for (int i = 0; i < n; i++)
      c[(i+n-s) % n] = sr, sr = (1LL * sr * g + seed) % p;
    t = (t + n - s) % n;
    int ans = 0, l = 0, r = n, ll = (l + c[0]), rr = (n-c[0]);
    while (t > l && t < r) {
      ans++;
      int tl = ll, tr = rr;
      bool ch = 0;
      while (l < min(ll, n-1)) {
        l++;
        tl = max(tl, l+c[l]);
        tr = min(tr, n+l-c[l]);
        ch = 1;
      }
      while (r > max(0, rr)) {
        r--;
        tr = min(tr, r-c[r]);
        tl = max(tl, r+c[r]-n);
        ch = 1;
      }
      ll = tl, rr = tr;
      if (!ch)
        break;
    }
    if (t > l && t < r)
      ans = -1;
    printf("%d\n", ans);
    return 0;
}