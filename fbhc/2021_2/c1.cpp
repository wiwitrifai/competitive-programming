#include <bits/stdc++.h>

using namespace std;

void solve() {
  int r, c, k;
  cin >> r >> c >> k;
  --k;
  vector<string> g(r);
  for (int i = 0; i < r; ++i) {
    cin >> g[i];
    assert((int)g[i].size() == c);
    for (int j = 0; j < c; ++j) {
      g[i][j] = (g[i][j] == 'X');
    }
  }
  int ans = 0;
  for (int i = 0; i < c; ++i)
    ans += g[k][i];
  vector<int> sum(c, 0);
  auto add = [&](int x) {
    for (int i = 0; i < c; ++i) {
      sum[i] += g[x][i];
    }
  };
  for (int i = 0; i <= k; ++i) {
    add(i);
  }
  for (int i = k+1; i < r; ++i) {
    int cur = abs(i - k);
    add(i);
    for (int j = 0; j < c; ++j) {
      if (g[i][j] || sum[j] >= k+1)
        ++cur;
    }
    ans = min(ans, cur);
  }
  {
    int cur = abs(r - k);
    for (int j = 0; j < c; ++j) {
      if (sum[j] >= k+1)
        ++cur;
    }
    ans = min(ans, cur);
  }
  sum.assign(c, 0);
  for (int i = k; i < r; ++i) {
    add(i);
  }
  int limit = r - k;
  for (int i = k-1; i >= 0; --i) {
    int cur = abs(k - i);
    add(i);
    for (int j = 0; j < c; ++j) {
      if (g[i][j] || sum[j] >= limit)
        ++cur;
    }
    ans = min(ans, cur);
  }
  {
    int cur = abs(k + 1);
    for (int j = 0; j < c; ++j) {
      if (sum[j] >= limit)
        ++cur;
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();

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
