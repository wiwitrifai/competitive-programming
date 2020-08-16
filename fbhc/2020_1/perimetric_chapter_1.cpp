#include <bits/stdc++.h>

using namespace std;


vector<int> read_sequence(int k, int n) {
  vector<int> s(n);
  for (int i = 0; i < k; ++i)
    scanf("%d", &s[i]);
  long long a, b, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  for (int i = k; i < n; ++i) {
    s[i] = ((a * s[i-2] + b * s[i-1] + c) % d) + 1;
  }
  return s;
}

const int mod = 1e9 + 7;

void solve() {
  int n, k, w;
  scanf("%d %d %d", &n, &k, &w);
  vector<int> l = read_sequence(k, n);
  vector<int> h = read_sequence(k, n);
  for (int i = 0; i + 1 < (int)l.size(); ++i) {
    assert(l[i] < l[i+1]);
  }

  long long perimeter = 0;
  long long ans = 1;
  deque<int> dq;
  for (int i = 0; i < n; ++i) {
    while (!dq.empty() && l[dq.front()] + w < l[i])
      dq.pop_front();
    if (dq.empty()) {
      perimeter += (w + h[i]) * 2;
    } else {
      perimeter += (l[i] - l[i-1]) * 2;
      perimeter += max(h[i] - h[dq.front()], 0) * 2;
    }
    while (!dq.empty() && h[dq.back()] <= h[i])
      dq.pop_back();
    dq.push_back(i);
    perimeter %= mod;
    ans = (ans * perimeter) % mod;
  }
  ans %= mod;
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
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
