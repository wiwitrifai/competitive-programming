#include <bits/stdc++.h>

using namespace std;

const int N = 6060, mod = 1e9 + 7;

int n, k, a, b;
int p[N];

vector<int> child[N];

void read_input() {
  scanf("%d %d %d %d", &n, &k, &a, &b);
  --a; --b;
  for (int i = 0; i < n; ++i)
    child[i].clear();
  for (int i = 1; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
    child[p[i]].push_back(i);
  }
}
long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

void solve() {
  vector<int> pa, pb;
  int now = a;
  while (1) {
    pa.push_back(now);
    if (now == 0)
      break;
    now = p[now];
  }
  now = b;
  while (1) {
    pb.push_back(now);
    if (now == 0)
      break;
    now = p[now];
  }
  reverse(pa.begin(), pa.end());
  reverse(pb.begin(), pb.end());
  int lca = 0;
  while (lca < pa.size() && lca < pb.size() && pa[lca] == pb[lca])
    ++lca;
  if (pa.size() > pb.size()) {
    pa.swap(pb);
    swap(a, b);
  }
  assert(b != 0);
  long long ans = 0;
  long long denom = powmod(n-1, mod-2);
  if (a == 0) {
    assert(lca == 1);
    for (int i = 1; i < pb.size(); ++i) {
      int sisa = (int)pb.size() - i - 1;
      sisa = n-1 - sisa;
      long long prob = 1LL * sisa * denom % mod;
      ans = (ans + powmod(prob, k)) % mod;
    }
    printf("%lld\n", ans);
    return;
  }
  ans = 0;
  auto calc = [denom](long long x, int c) {
    assert(c >= 0 && c <= 2);
    assert(x <= n-1 && x >= c);
    if (c == 0)
      return powmod(x * denom % mod, k);
    else if (c == 1) {
      return (powmod(x * denom % mod, k) - powmod((x-1) * denom % mod, k) + mod) % mod;
    }
    long long ret = powmod(x * denom % mod, k) - 2LL * powmod((x-1) * denom % mod, k) + powmod((x-2) * denom % mod, k);
    ret%= mod;
    if (ret < 0)
      ret += mod;
    return ret;
  };
  for (int i = lca; i < pa.size(); ++i) {
    for (int j = lca; j < pb.size(); ++j) {
      int sisa = (int)pa.size() - i - 1 + (int)pb.size() - j - 1;
      int lain = n - 1 - sisa;
      ans = (ans + 1LL * calc(lain, 2) * (sisa + 2)) % mod;
    }
    for (int j = 0; j < lca; ++j) {
      int sisa = (int)pa.size() - i - 1 + (int)pb.size() - j - 1;
      int lain = n - 1 - sisa;
      int dist = sisa + 1 + (j != 0);
      ans = (ans + 1LL * calc(lain, 1 + (j != 0)) * dist) % mod;
    }
  }
  for (int i = lca; i < (int)pb.size(); ++i) {
    for (int j = 0; j < lca; ++j) {
      int sisa = (int)pb.size() - i - 1 + (int)pa.size() - j - 1;
      int lain = n - 1 - sisa;
      int dist = sisa + 1 + (j != 0);
      ans = (ans + 1LL * calc(lain, 1 + (j != 0)) * dist) % mod;
    }
  }
  int sisa = (pb.size() + pa.size() - 2 * lca);
  ans = (ans + 1LL * calc(n-1-sisa, 0) * sisa) % mod;
  if (ans < 0)
    ans += mod;
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
