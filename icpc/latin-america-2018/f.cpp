#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int b[N], f[N], d[N];

long long bit[N];

long long get(int x) {
  long long ret = 0;
  for (++x; x; x -= x&-x)
    ret = max(ret, bit[x]);
  return ret;
}

void upd(int x, long long v) {
  for (++x; x < N; x += x&-x)
    bit[x] = max(bit[x], v);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vb, vf;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", b+i, f+i, d+i);
    vb.push_back(b[i]);
    vf.push_back(f[i]);
  }
  sort(vb.begin(), vb.end());
  vb.erase(unique(vb.begin(), vb.end()), vb.end());
  sort(vf.begin(), vf.end());
  vf.erase(unique(vf.begin(), vf.end()), vf.end());
  for (int i = 0; i < n; ++i) {
    b[i] = lower_bound(vb.begin(), vb.end(), b[i]) - vb.begin();
    f[i] = lower_bound(vf.begin(), vf.end(), f[i]) - vf.begin();
  }
  vector<tuple<int, int, long long> > vs;
  for (int i = 0; i < n; ++i) {
    vs.emplace_back(b[i], f[i], (long long)d[i]);
  }
  int lb, lf;
  long long ld;
  sort(vs.begin(), vs.end());
  vector<tuple<int, int, long long> > diff;
  lb = lf = ld = -1;
  for (int i = 0; i < n; ++i) {
    int bb, ff;
    long long dd;
    tie(bb, ff, dd) = vs[i];
    if (bb != lb || ff != lf) {
      if (ld > 0) {
        diff.emplace_back(lb, lf, ld);
      }
      lb = bb, lf = ff;
      ld = 0;
    }
    ld += dd;
  }
  if (ld > 0)
    diff.emplace_back(lb, lf, ld);
  for (int i = 0; i < diff.size(); ) {
    int j = i;
    int bnow = get<0>(diff[i]);
    while (j < diff.size() && get<0>(diff[j]) == bnow) ++j;
    vector<pair<int, long long> > vp;
    for (int k = i; k < j; ++k) {
      int fnow;
      long long dnow;
      tie(ignore, fnow, dnow) = diff[k];
      long long cur = dnow + get(fnow-1);
      vp.emplace_back(fnow, cur);
    }
    for (auto it : vp) {
      upd(it.first, it.second);
    }
    i = j;
  }
  printf("%lld\n", get(vf.size()));
  return 0;
}