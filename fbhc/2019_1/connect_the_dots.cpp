#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5, inf = 2e9 + 7;
int n, h, v;
int x[N], y[N];

void generate_array(int ar[N]) {
  scanf("%d %d", ar, ar+1);
  long long a, b, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  for (int i = 2; i < n; ++i) {
    ar[i] = ((a * ar[i-2] + b * ar[i-1] + c) % d) + 1;
  }
}

vector<int> compress(int ar[N]) {
  vector<int> var(n+1, 0);
  for (int i = 0; i < n; ++i)
    var[i] = ar[i];
  sort(var.begin(), var.end());
  var.erase(unique(var.begin(), var.end()), var.end());
  for (int i = 0; i < n; ++i)
    ar[i] = lower_bound(var.begin(), var.end(), ar[i]) - var.begin();
  return var;
}

int bit[N];

void upd(int id, int v) {
  for (++id; id < N; id += id & -id)
    bit[id] += v;
}

int get_id(int v) {
  int ret = 0;
  for (int len = 1 << 20; len; len >>= 1) {
    if ((ret + len) >= N) continue;
    int now = ret + len;
    if (bit[now] < v) {
      v -= bit[now];
      ret = now;
    }
  }
  return ret;
}


void read_input() {
  scanf("%d %d %d", &n, &h, &v);
  assert(2 <= n && n <= int(8e5));
  assert(0 <= h && h <= n);
  assert(0 <= v && v <= n);
  generate_array(x);
  generate_array(y);
  set<pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    assert(1 <= x[i] && x[i] <= int(1e9));
    assert(1 <= y[i] && y[i] <= int(1e9));
    assert(!vp.count({x[i], y[i]}));
    vp.insert({x[i], y[i]});
  }
}

void solve() {
  if (v + h < n) {
    puts("-1");
    return;
  }
  vector<int> vx = compress(x);
  vector<int> vy = compress(y);
  vector<int> id(n);
  iota(id.begin(), id.end(),0);
  sort(id.begin(), id.end(), [](int l, int r) {
    return (x[l] == x[r]) ? y[l] > y[r] : x[l] < x[r];
  });
  int ans = inf;
  memset(bit, 0, sizeof bit);
  for (int i = 0; i < n; ++i) {
    upd(y[i], +1);
  }
  int maxy = 0;
  for (int i = n; i >= 0; --i) {
    if (i < n) {
      maxy = max(y[id[i]], maxy);
      upd(y[id[i]], -1);
    }
    int curx = i > 0 ? x[id[i-1]] : 0, cury = maxy;
    int cv = n-i, ch = i;
    if (cv > v) continue;
    if (ch > h) {
      int need = ch - h;
      assert(cv + need <= v);
      cury = max(cury, get_id(need));
    }
    assert(0 <= curx && curx < (int)vx.size());
    assert(0 <= cury && cury < (int)vy.size());
    ans = min(ans, vx[curx] + vy[cury]);
  }
  printf("%d\n", ans);
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
