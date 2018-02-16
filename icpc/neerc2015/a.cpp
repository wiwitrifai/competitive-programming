#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;
bool usedc[N], usedr[N];

long long calc(int le, int ri) {
  long long ret = 1LL * (ri - le + 1) * (le + ri) / 2;
  return ret;
}


void open(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}
int main() {
  open("adjustment");
  int n, q;
  scanf("%d %d", &n, &q);
  long long sumr = 0, sumc = 0;
  int cntr = 0, cntc = 0;
  for (int i = 0; i < q; ++i) {
    char c;
    int x;
    scanf(" %c %d", &c, &x);
    long long ans = 0;
    if (c == 'R') {
      if (!usedr[x]) {
        ans = calc(x+1, x+n) - sumc - 1LL * cntc * (x-1);
        ++cntr;
        sumr += x+1;
        usedr[x] = 1;
      }
    }
    else {
      if (!usedc[x]) {
        ans = calc(x+1, x+n) - sumr - 1LL * cntr * (x-1);
        ++cntc;
        sumc += x+1;
        usedc[x] = 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}