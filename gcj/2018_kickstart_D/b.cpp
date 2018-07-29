#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int p[N], h[N], x[N], y[N];

void read(int v[N], int n) {
  int v1, v2, a, b, c, m;
  scanf("%d %d %d %d %d %d", &v1, &v2, &a, &b, &c, &m);
  v[0] = v1;
  v[1] = v2;
  for (int i = 2; i < n; ++i) {
    v[i] = 1 + ((1LL * a * v[i-1] + 1LL * b * v[i-2] + c) % m);
  }
  // for (int i = 0; i < n; ++i)
  //   cerr << v[i] << ", ";
  // cerr << endl;
}

int bit[N];

int get(int x) {
  int ret = -1e9;
  for (; x; x -= x&-x)
    ret = max(ret, bit[x]);
  return ret;
}

void upd(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] = max(bit[x], v);
}

void solve(int tc) {
  int n, k;
  scanf("%d %d", &n, &k);
  read(p, n);
  read(h, n);
  read(x, k);
  read(y, k);
  vector<int> vx;
  for (int i = 0; i < n; ++i)
    vx.push_back(p[i] - h[i]);
  for (int i = 0; i < k; ++i)
    vx.push_back(x[i] - y[i]);
  memset(bit, -1, sizeof bit);
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  assert(vx.size() < N);
  for (int i = 0; i < n; ++i) {
    int le = p[i] - h[i], ri = p[i] + h[i];
    le = lower_bound(vx.begin(), vx.end(), le) - vx.begin() + 1;
    upd(le, ri);
  }
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    int le = x[i] - y[i], ri = x[i] + y[i];
    le = lower_bound(vx.begin(), vx.end(), le) - vx.begin() + 1;
    int res = get(le);
    ans += res >= ri;
  }
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) /CLOCKS_PER_SEC << "s" << endl;
  }
  return 0;
}