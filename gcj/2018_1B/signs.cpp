#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], d[N], n;

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    scanf("%d", &n);
    vector<int> va, vb;
    for (int i = 0; i < n; ++i) {
      scanf("%d %d %d", d+i, a+i, b+i);
      va.push_back(d[i]+a[i]);
      vb.push_back(d[i]-b[i]);
      // cerr << i << " cek " <<  d[i]+a[i] << " " << d[i]-b[i] << endl;
    }
    sort(va.begin(), va.end());
    va.erase(unique(va.begin(), va.end()), va.end());
    sort(vb.begin(), vb.end());
    vb.erase(unique(vb.begin(), vb.end()), vb.end());
    vector<pair<int, int> > cand;
    for (int x : va) {
      for (int y : vb) {
        int last = 0;
        for (int i = 0; i < n; ++i) {
          if (((d[i]+a[i]) == x) || ((d[i]-b[i]) == y));
          else {
            if (last < i)
              cand.emplace_back(last, i);
            last = i+1;
          }
        }
        if (last < n)
          cand.emplace_back(last, n);
      }
    }
    int best = 0, cnt = 0;
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    for (auto it : cand) {
      int now = it.second - it.first;
      if (now > best) {
        best = now;
        cnt = 1;
      }
      else if (now == best) ++cnt;
    }
    printf("Case #%d: %d %d\n", tc, best, cnt);
  }
  return 0;
}