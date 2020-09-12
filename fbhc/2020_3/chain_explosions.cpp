#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, inf = 1e9 + 7;

int dp[N], cnt[N], pick[N];

void solve() {
  long long k;
  scanf("%lld", &k);
  assert((k & 1) == 0);
  k /= 2;
  int ak = k;
  int nodes = 2, center = 2;
  vector<pair<int, int>> edges;
  edges.emplace_back(1, 2);
  while (k > 0) {
    int p = pick[k];
    for (int i = 0; i < p; ++i) {
      edges.emplace_back(center, ++nodes);
    }
    center = nodes;
    k -= cnt[p];
  }
  printf("%d %d\n", nodes, (int)edges.size());
  assert((int)edges.size() == dp[ak]);
  for (auto e : edges) {
    printf("%d %d\n", e.first, e.second);
  }
}

int main(int argc, char * argv[]) {
  dp[0] = 1;
  cnt[0] = 0;
  for (int i = 1; i < N; ++i) {
    cnt[i] = 1LL * i * (i+1) / 2;
    if (cnt[i] > N) break;
  }
  int maxi = -1;
  for (int i = 1; i < N; ++i) {
    dp[i] = inf;
    for (int j = 1; cnt[j] <= i; ++j) {
      int now = dp[i-cnt[j]] + j;
      if (dp[i] > now) {
        dp[i] = now;
        pick[i] = j;
      }
    }
    maxi = max(maxi, dp[i]);
  }
  cerr << "Max M: " << maxi << endl;
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
