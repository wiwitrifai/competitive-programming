#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int n, ma[N << 2], sum[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  ma[id] = sum[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void upd(int x, int val, int id = 1, int l = 0, int r = n) {
  sum[id]++;
  if (ma[id] < val)
    ma[id] = val;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1;
  if (x < mid)
    upd(x, val, id + id, l, mid);
  else
    upd(x, val, id + id + 1 , mid, r);
}
pair< int, int > get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return make_pair(0, 0);
  if (x <= l && r <= y) return make_pair(ma[id], sum[id]);
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  pair< int, int > lhs = get(x, y, il, l, mid), rhs = get(x, y, ir, mid, r);
  return make_pair(max(lhs.first, rhs.first), lhs.second + rhs.second);
}

int p[N], up[N], res[N], pos[N];
pair< int, int > ral[N], rar[N];
pair< int, int > lhs[N], rhs[N];
vector< int > que[N];
long long ans[N];
const int mod = 1e9 + 7;
long long fac[N], inv[N];
long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}
long long calc(int l, int r) {
  return (l <= 0) ? 0 : (fac[r] * inv[l-1]) % mod;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
      scanf("%d", p+i), pos[p[i]] = i;
    build();
    for (int i = 0; i < n; i++)
      upd(i, p[i]);
    for (int i = 0; i < q; i++) {
      int tmp[4];
      for (int j = 0; j < 4; j++)
        scanf("%d", tmp+j);
      tmp[0]--; tmp[2]--;
      ral[i] = make_pair(tmp[0], tmp[1]);
      rar[i] = make_pair(tmp[2], tmp[3]);
      
      res[i] = 0;
      lhs[i] = get(tmp[0], tmp[1]);
      rhs[i] = get(tmp[2], tmp[3]);
      ans[i] = 1;

      up[i] = max(lhs[i].first, rhs[i].first);
      que[up[i]].push_back(i);
    }
    bool ok = 1;
    while (ok) {
      ok = 0;
      build();
      for (int j = 0; j <= n; j++) {
        if (j > 0)
          upd(pos[j], j);
        for (int id : que[j]) {
          auto le = get(ral[id].first, ral[id].second), ri = get(rar[id].first, rar[id].second);

          if (le.first <= ri.first) {
            int cnt = lhs[id].second - le.second;
            if (cnt > res[id]) {
              ans[id] = 0;
              continue;
            }
            ans[id] = (ans[id] * calc(res[id] - cnt + 1, res[id])) % mod;
            res[id] -= cnt;
          }
          else
            res[id] += rhs[id].second - ri.second;
          lhs[id] = le, rhs[id] = ri;
          if (up[id]) {
            up[id] = min(le.first, ri.first);
            que[up[id]].push_back(id);
            ok = 1;
          }
        }
        que[j].clear();
      }
    }
    for (int i = 0; i < q; i++)
      printf("%lld\n", ans[i]);
  }
  return 0;
}