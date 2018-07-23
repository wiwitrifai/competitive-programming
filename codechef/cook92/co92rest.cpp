#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int n, m, k;
int a[N];

int ic[N], dc[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
    }
    fill(ic, ic+n, 0);
    fill(dc, dc+n, 0);
    for (int i = 0; i < m; ++i) {
      char c;
      int l, r;
      scanf(" %c %d %d", &c, &l, &r);
      --l; --r;
      if (c == 'I')
        ++ic[l], --ic[r];
      else
        ++dc[l], --dc[r];
    }
    int ans = 1;
    for (int i = 0; i+1 < n; ++i) {
      if (ic[i] > 0 && dc[i] > 0) {
        ans = 0;
        break;
      }
      ic[i+1] += ic[i];
      dc[i+1] += dc[i];
    }
    if (ans == 0) {
      puts("0");
      continue;
    }
    int mi = 1e9, ma = -1e9, off = 0;
    bool ok = 0;
    int now = 0, last = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != -1 && !ok) {
        ok = 1;
        off = a[i]-now;
      }
      mi = min(mi, now);
      ma = max(ma, now);
      if (ic[i] == 0 && dc[i] == 0) {
        if (ok) {
          if (mi+off < 1 || ma+off > k) {
            goto FAIL;
          }
          now = 0;
          for (int j = last; j <= i; ++j) {
            if (a[j] != -1 && a[j] != now + off) {
              goto FAIL;
            }
            if (ic[j]) ++now;
            else --now;
          }
        }
        else {
          if (ma - mi >= k)
            goto FAIL;
          ans = (ans * 1LL * (k - (ma-mi))) % mod;
        }
        if (i+1 < n) {
          ok = 0;
          mi = 1e9, ma = -1e9;
          off = now = 0;
          last = i+1;
        }
      }
      else {
        if (ic[i]) ++now;
        else --now;
      }
    }
    printf("%d\n", ans);
    goto DONE;
    FAIL:;
    puts("0");
    DONE:;
  }
  return 0;
}