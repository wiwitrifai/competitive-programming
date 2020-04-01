#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void normalize(int & v) {
  if (v >= mod)
    v -= mod;
  if (v < 0)
    v += mod;
}

vector<int> pw2(1, 1);

int pow2(int k) {
  while ((int)pw2.size() <= k)
    pw2.push_back(pw2.back() * 2LL % mod);
  return pw2[k];
}

struct SegTree {
  int n;
  vector<int> sum, lazy;
  SegTree(int _n) : n(_n), sum(n << 2, 0), lazy(n << 2, 0) {};
  void apply(int id, int v) {
    if (v == 0) return;
    lazy[id] += v;
    sum[id] = (long long) pow2(v) * sum[id] % mod;
  }
  inline void push(int id, int il, int ir) {
    if (lazy[id] == 0) return;
    apply(il, lazy[id]);
    apply(ir, lazy[id]);
    lazy[id] = 0;
  }
  inline void combine(int id, int il, int ir) {
    sum[id] = (sum[il] + sum[ir]);
    if (sum[id] >= mod)
      sum[id] -= mod;
  }

  void _upd(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      apply(id, 1);
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id, il, ir);
    _upd(x, y, il, l, mid);
    _upd(x, y, ir, mid, r);
    combine(id, il, ir);
  }
  void upd(int x, int y) {
    _upd(x, y, 1, 0, n);
  }
  void _add(int x, int v, int id, int l, int r) {
    if (r-l < 2) {
      sum[id] = (sum[id] + v);
      if (sum[id] >= mod)
        sum[id] -= mod;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id, il, ir);
    if (x < mid)
      _add(x, v, il, l, mid);
    else
      _add(x, v, ir, mid, r);
    combine(id, il, ir);
  }
  void add(int x, int v) {
    _add(x, v, 1, 0, n);
  }

  int _get(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return 0;
    if (x <= l && r <= y) {
      return sum[id];
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    push(id, il, ir);
    int res = _get(x, y, il, l, mid) +_get(x, y, ir, mid, r);
    if (res >= mod)
      res -= mod;
    return res;
  }
  int get(int x, int y) {
    return _get(x, y, 1, 0, n);
  }
};

int main() {
  const string problem_name = "help";
  freopen((problem_name + ".in").c_str(), "r", stdin);
  freopen((problem_name + ".out").c_str(), "w", stdout);

  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> rig(n);
  vector<pair<int, int>> seg(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;
    seg[i] = {l, r};
    rig[i] = r;
  }
  sort(rig.begin(), rig.end());
  for (int i = 0; i < n; ++i) {
    seg[i].first = lower_bound(rig.begin(), rig.end(), seg[i].first) - rig.begin();
    seg[i].second = lower_bound(rig.begin(), rig.end(), seg[i].second) - rig.begin();
  }

  vector<vector<long long>> C(k+1);
  for (int i = 0; i <= k; ++i) {
    C[i].resize(i+1);
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
      normalize(C[i][j]);
    }
  }
  vector<SegTree> dp(k+1, SegTree(n));
  sort(seg.begin(), seg.end());
  vector<long long> add(k+1, 0);
  for (auto it : seg) {
    int l = it.first, r = it.second;
    fill(add.begin(), add.end(), 0);
    for (int i = k; i >= 0; --i) {
      int res = dp[i].get(l, r+1);
      dp[i].add(r, res);
      dp[i].upd(r+1, n);
      int cur = dp[i].get(0, l) + (i == 0);
      for (int j = i; j <= k; ++j) {
        add[j] = (add[j] + C[j][i] * cur);
      }
    }
    for (int i = 0; i <= k; ++i)
      dp[i].add(r, add[i] % mod);
  }
  printf("%d\n", dp.back().get(0, n));

  fclose(stdin);
  fclose(stdout);
  return 0;
}
