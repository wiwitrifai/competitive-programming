#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5;
const long long infll = 1e18;

void generate(int n, int x[N]) {
  long long p, q, a, b, c, d;
  scanf("%lld %lld %lld %lld %lld %lld", &p, &q, &a, &b, &c, &d);
  x[0] = p;
  x[1] = q;
  for (int i = 2; i < n; ++i) {
    x[i] = 1LL + ((1LL * a * x[i-2] + 1LL * b * x[i-1] + c) % d);
  }
}

int n;

int p[N], h[N];
char s[N];
int lef[N], rig[N];

int sum[N << 2], mini[N << 2], lazy[N << 2];

void build(int id = 1, int l = 0, int r = n) {
  mini[id] = lazy[id] = 0;
  sum[id] = p[r] - p[l];
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

inline void upd(int id, int v) {
  mini[id] += v;
  lazy[id] += v;
}

inline void push(int id, int il, int ir) {
  if (lazy[id] == 0) return;
  upd(il, lazy[id]);
  upd(ir, lazy[id]);
  lazy[id] = 0;
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, v);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  update(x, y, v, il, l, mid);
  update(x, y, v, ir, mid, r);
  if (mini[il] < mini[ir]) {
    mini[id] = mini[il];
    sum[id] = sum[il];
  }
  else if (mini[ir] < mini[il]) {
    mini[id] = mini[ir];
    sum[id] = sum[ir];
  }
  else {
    mini[id] = mini[il];
    sum[id] = sum[il] + sum[ir];
  }
}

void check(int id = 1, int l = 0, int r = n) {
  cerr << id << " [" << l << ", " << r << "] =";
  cerr << sum[id] << " "<< mini[id] << endl;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id, il, ir);
  check(il, l, mid);
  check(ir, mid, r);
}

long long get() {
  if (mini[1] == 0)
    return p[n] - p[0] - sum[1];
  return p[n] - p[0];
}

void read_input() {
  scanf("%d", &n);
  generate(n, p);
  generate(n, h);
  scanf("%s", s);
}

int id[N], tmp[N];
void renumber(int x[N]) {
  for (int i = 0; i < n; ++i)
    tmp[i] = x[id[i]];
  for (int i = 0; i < n; ++i)
    x[i] = tmp[i];
}
void renumber_char(char x[N]) {
  for (int i = 0; i < n; ++i)
    tmp[i] = x[id[i]];
  for (int i = 0; i < n; ++i)
    x[i] = tmp[i];
}

void solve() {
  iota(id, id+n, 0);
  sort(id, id+n, [](int l, int r) {
    return p[l] < p[r];
  });
  renumber(p);
  for (int i = 0; i + 1 < n; ++i)
    assert(p[i] < p[i+1]);
  renumber(h);
  renumber_char(s);
  iota(id, id+n, 0);
  fill(lef, lef+n, -1);
  vector<pair<int, int>> rocks;
  int last = -1;
  for (int i = 0; i < n; ++i) {
    int v = i;
    if (s[v] == 'C') {
      int pos = lower_bound(rocks.begin(), rocks.end(), make_pair(-h[v], -1)) - rocks.begin() - 1;
      if (pos >= 0) {
        lef[v] = rocks[pos].second;
      }
      last = i;
    }
    else {
      while (!rocks.empty() && rocks.back().first >= -h[v]) rocks.pop_back();
      rocks.emplace_back(-h[v], v);
    }
  }
  assert(last != -1);
  p[n] = p[n-1];
  long long ans = infll;
  {
    build();
    int cnt = 0;
    set<pair<int, int>> st;
    for (int i = 0; i <= last; ++i) {
      int v = i;
      if (s[v] == 'C') {
        st.insert(make_pair(h[v], v));
        if (lef[v] == -1)
          ++cnt;
        else
          update(lef[v], v, +1);
      }
      else {
        while (!st.empty()) {
          auto it = st.begin();
          if (it->first >= h[v]) break;
          int cur = it->second;
          st.erase(it);
          if (lef[cur] == -1)
            --cnt;
          else
            update(lef[cur], cur, -1);
        }
      }
    }
    for (int i = last+1; i < n; ++i) {
      int v = i;
      while (!st.empty()) {
        auto it = st.begin();
        if (it->first >= h[v]) break;
        int cur = it->second;
        st.erase(it);
        if (lef[cur] == -1)
          --cnt;
        else
          update(lef[cur], cur, -1);
      }
      assert(cnt >= 0);
      if (cnt == 0) {
        ans = min(ans, p[i] + 2LL * get());
      }
    }
  }
  {
    build();
    int cnt = 0;
    set<pair<int, int>> st;
    for (int i = 0; i <= last; ++i) {
      int v = i;
      if (s[v] == 'C') {
        st.insert(make_pair(h[v], v));
        if (lef[v] == -1)
          ++cnt;
        else
          update(lef[v], v, +1);
      }
      else {
        while (!st.empty()) {
          auto it = st.begin();
          if (it->first >= h[v]) break;
          int cur = it->second;
          st.erase(it);
          if (lef[cur] == -1)
            --cnt;
          else
            update(lef[cur], cur, -1);
        }
      }
    }
    for (int i = last-1; i >= 0; --i) {
      if (s[i] == 'C') continue;
      int v = i;
      while (!st.empty()) {
        auto it = st.begin();
        if (it->first >= h[v]) break;
        int cur = it->second;
        st.erase(it);
        if (lef[cur] == -1)
          --cnt;
        else
          update(lef[cur], cur, -1);
      }
      assert(cnt >= 0);
      if (cnt == 0) {
        ans = min(ans, 2LL * p[last] - p[i] + 2LL * get());
      }
    }
  }
  if (ans >= infll)
    ans = -1;
  printf("%lld\n", ans);
}


int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
