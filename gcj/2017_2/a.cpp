#include <bits/stdc++.h>

using namespace std;

int n, p, c[5];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    scanf("%d %d", &n, &p);
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; i++) {
      int g;
      scanf("%d", &g);
      g %= p;
      c[g]++;
    }
    int ans = 0;
    if (p == 2) {
      if (c[1]) c[1]--;
      else c[0]--;
      ans = 1 + c[0] + c[1]/2;
    }
    else if (p == 3) {
      if (c[1] + c[2]) {
        if (c[1] > c[2]) c[1]--;
        else c[2]--;
      }
      else
        c[0]--;
      ans = 1 + c[0];
      int r = min(c[1], c[2]);
      ans += r;
      c[1] -= r;
      c[2] -= r;
      ans += c[1]/3 + c[2]/3;
    }
    else {
      ans = 1;
      for (int i = 0; i < 4; i++) {
        if (c[i] == 0) continue;
        c[i]--;
        int cur = 1 + c[0];
        int c1 = c[1], c2 = c[2], c3 = c[3];
        int r = c2/2;
        // 2
        c2 -= 2 * r;
        cur += r;
        r = min(c1, c3);
        cur += r;
        c1 -= r;
        c3 -= r;
        // 3
        int d1 = c1, d2 = c2, d3 = c3;
        int op1 = 0;
        r = min(d2, d1/2);
        op1 += r;
        d2 -= r;
        d1 -= r * 2;
        r = min(d2, d3/2);
        op1 += r;
        d2 -= r;
        d3 -= r * 2;
        op1 += d2/4 + d3/4;
        d1 = c1, d2 = c2, d3 = c3;
        int op2 = 0;
        r = min(d2, d3/2);
        op2 += r;
        d2 -= r;
        d3 -= r * 2;
        r = min(d2, d1/2);
        op2 += r;
        d2 -= r;
        d1 -= r * 2;
        op2 += d2/4 + d3/4;
        cur += max(op1, op2);
        ans = max(ans, cur);
        c[i]++;
      }
    }
    ans = min(ans, n);
    printf("Case #%d: %d\n", tc, ans);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}