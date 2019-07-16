#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

char s[N], p[5];
int n;

void b1() {
  int ans = 1;
  if (p[0] == 'T' || p[0] == 'B') {
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'T' || s[i] == 'B') continue;
      ans = (ans * 2) % mod;
    }
  }
  else {
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L' || s[i] == 'R') continue;
      ans = (ans * 2) % mod;
    }
  }
  ans = (ans + 1) % mod;
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s %s", &n, s, p);
    string pola = p;
    if (pola == "LR" || pola == "RL" || pola == "BT" || pola == "TB") {
      b1();
      continue;
    }
    long long ans = 2;
    long long ll = 0, rr = 0, bb = 0, tt = 0;
    long long lb = 0, lt = 0, rb = 0, rt = 0;
    if (pola == "LB" || pola == "BL")
      ++lb;
    else if(pola == "RB" || pola == "BR")
      ++rb;
    else if(pola == "RT" || pola == "TR")
      ++rt;
    else if(pola == "LT" || pola == "TL")
      ++lt;
    else
      assert(false);
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == 'T') {
        ans = (ans * 2 - lt - tt - rt - 1) % mod;
        ll = (2 * ll + lt) % mod;
        rr = (2 * rr + rt) % mod;
        lt = lb;
        rt = rb;
        tt = bb;
      }
      else if (s[i] == 'B') {
        ans = (ans * 2- lb - bb - rb - 1) % mod;
        ll = (2 * ll + lb) % mod;
        rr = (2 * rr + rb) % mod;
        lb = lt;
        rb = rt;
        bb = tt;
      }
      else if (s[i] == 'L') {
        ans = (ans * 2 - ll - lt - lb - 1) % mod;
        tt = (2 * tt + lt) % mod;
        bb = (2 * bb + lb) % mod;
        lb = rb;
        lt = rt;
        ll = rr;
      }
      else if (s[i] == 'R') {
        ans = (ans * 2 - rr - rt - rb - 1) % mod;
        tt = (2 * tt + rt) % mod;
        bb = (2 * bb + rb) % mod;
        rb = lb;
        rt = lt;
        rr = ll;
      }
      else
        assert(false);
    }
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}