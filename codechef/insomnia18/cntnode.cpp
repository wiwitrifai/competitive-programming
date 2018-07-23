#include <bits/stdc++.h>

using namespace std;

const int LG = 40;

struct node {
  long long le[LG], ri[LG], cnt[LG];
  node() {
    memset(le, 0, sizeof le);
    memset(ri, 0, sizeof ri);
    memset(cnt, 0, sizeof cnt);
  }
  node operator+(node ot) {
    node ret;
    for (int i = 0; i < LG; ++i) {
      ret.cnt[i] += cnt[i] + ot.cnt[i];
      ret.le[i] += le[i] + (i ? ot.le[i-1] : 0);
      ret.ri[i] += ot.ri[i] + (i ?ri[i-1] : 0);
    }
    for (int i = 0; i < LG; ++i) {
      if (ri[i] == 0) continue;
      for (int j = 0; j < LG; ++j) {
        if (ot.le[j] == 0) continue;
        ret.cnt[i+j] += ri[i] * ot.le[j];
      }
    }
    --ret.cnt[2];
    ++ret.cnt[1];
    --ret.le[2];
    ++ret.le[1];
    --ret.ri[2];
    ++ret.ri[1];
    return ret;
  }
};

node solve(int l, int r) {
  if (r - l < 2) {
    node res;
    res.cnt[1] = res.le[1] = res.ri[1] = 1;
  //   cerr << l << " " << r << endl;

  //   for (int i = 0; i < LG; ++i)
  //     cerr << res.cnt[i] << " ";
  //   cerr << endl;
  // for (int i = 0; i < LG; ++i)
  //   cerr << res.le[i] << " ";
  // cerr << endl;
  // for (int i = 0; i < LG; ++i)
  //   cerr << res.ri[i] << " ";
  // cerr << endl;
    return res;
  }
  int mid = (l + r) >> 1;
  node le = solve(l, mid), ri = solve(mid, r);
  node res = le + ri;
  // cerr << l << " " << r << endl;
  // for (int i = 0; i < LG; ++i)
  //   cerr << res.cnt[i] << " ";
  // cerr << endl;
  // for (int i = 0; i < LG; ++i)
  //   cerr << res.le[i] << " ";
  // cerr << endl;
  // for (int i = 0; i < LG; ++i)
  //   cerr << res.ri[i] << " ";
  // cerr << endl;
  return res;
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    node ans = solve(0, n);
    int k = 1;
    for (int i = 0; i < LG; ++i)
      if (ans.cnt[i] > 0)
        k = i;
    printf("%d\n", k);
    for (int i = 1; i <= k; ++i) {
      printf("%lld%c", ans.cnt[i], i == k ? '\n' : ' ');
    }
  }
  return 0;
}