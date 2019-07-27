#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> g, l;

void read_input() {
  int n;
  scanf("%d", &n);
  g.clear();
  l.clear();
  for (int i = 0; i < n; ++i) {
    char buf[5];
    int v, r;
    scanf("%s %d %d", buf, &v, &r);
    if (buf[0] == 'G')
      g.emplace_back(v, r);
    else {
      assert(buf[0] == 'L');
      l.emplace_back(v, r);
    }
  }
}
const int N = 1e6 + 5, X = 1e9;
bool isc[N];
vector<int> primes;
map<int, int> factorize(int x) {
  map<int, int> result;
  for (int p : primes) {
    if (1LL * p * p > x)
      break;
    if (x % p) continue;
    int cnt = 0;
    while ((x % p) == 0) {
      ++cnt;
      x /= p;
    }
    result[p] = cnt;
  }
  if (x > 1)
    ++result[x];
  return result;
}

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

void solve() {
  map<int, int> low, high;
  for (auto it : g) {
    int v, r;
    v = it.first;
    r = it.second;
    if (v % r) {
      puts("-1");
      return;
    }
    map<int, int> fv = factorize(v), fr = factorize(r);
    for (auto f : fv) {
      int val = f.first, lo = fr[val], hi = f.second;
      if (lo < hi) {
        low[val] = high[val] = lo;
      }
      else {
        low[val] = max(low[val], lo);
      }
    }
  }
  for (auto it : l) {
    int v, r;
    v = it.first;
    r = it.second;
    if (r % v) {
      puts("-1");
      return;
    }
    map<int, int> fv = factorize(v), fr = factorize(r);
    for (auto f : fr) {
      int val = f.first, lo = fv[val], hi = f.second;
      if (lo < hi) {
        low[val] = high[val] = hi;
      }
      else {
        if (high.find(val) == high.end())
          high[val] = hi;
        else
          high[val] = min(high[val], hi);
      }
    }
  }
  long long ret = 1;
  for (auto it : low) {
    int p = it.first, cnt = it.second;
    while (ret <= X && cnt-- > 0) {
      ret *= p;
    }
  }
  if (ret > X) {
    puts("-1");
    return;
  }
  for (auto it : g) {
    if (gcd(ret, it.first) != it.second) {
      puts("-1");
      return;
    }
  }
  for (auto it : l) {
    int d = gcd(ret, it.first);
    long long val = 1LL * (ret / d) * it.first;
    if (val != it.second) {
      puts("-1");
      return;
    }
  }
  printf("%lld\n", ret);
}

int main(int argc, char * argv[]) {
  for (int i = 2; i < N; ++i) {
    if (isc[i]) continue;
    primes.push_back(i);
    for (int j = i+i; j < N; j += i)
      isc[j] = 1;
  }
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
