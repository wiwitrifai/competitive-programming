#include <bits/stdc++.h>

using namespace std;

const int N = 333, inf = 1e9 + 7;

char g[N][N];
int h, s, k;
int a[N * N];
int pos[N];

void read_input() {
  scanf("%d %d %d", &h, &s, &k);
  for (int i = 0; i < h; ++i)
    scanf("%s", g[i]);
  for (int i = 0; i < k; ++i)
    scanf("%d", a+i);
}

int dp[N][N];

void upd(int &var, int val) {
  if (var > val)
    var = val;
}

vector<int> solve1() {
  int up = h+2;
  vector<int> res(up, 0);
  for (int j = 0; j < s; ++j) {
    char last = 'A';
    int cnt = 0;
    vector<int> st;
    for (int i = 0; i < h; ++i) {
      if (last != g[i][j]) {
        st.push_back(cnt);
        cnt = 0;
        last = g[i][j];
      }
      ++cnt;
    }
    if (cnt > 0)
      st.push_back(cnt);
    for (int i = 0; i <= (int)st.size(); ++i)
      for (int j = 0; j < up; ++j)
        dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 0; i < (int)st.size(); ++i) {
      for (int j = 0; j < up; ++j) {
        if (dp[i][j] >= inf) continue;
        if (j > 0 && (j&1) == ((i+1)&1)) {
          upd(dp[i+1][j], dp[i][j]);
        }
        upd(dp[i+1][j], dp[i][j]+st[i]);
        if (j+1 < up && (j&1) == (i&1))
          upd(dp[i+1][j+1], dp[i][j]);
      }
    }
    int sz = st.size();
    int best = inf;
    for (int i = 0; i < up; ++i) {
      upd(best, dp[sz][i]);
      res[i] += best;
    }
  }
  return res;
}

void solve() {
  vector<int> res = solve1();
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < s; ++j) {
      g[i][j] = 'B' - g[i][j] + 'A';
    }
  vector<int> res2 = solve1();
  int best = inf;
  for (int i = 0; i < (int)res.size(); ++i) {
    best = min(best, min(res[i], res2[i]));
    res[i] = best;
  }
  res.push_back(0);
  reverse(res.begin(), res.end());
  for (int i = 0; i < k; ++i) {
    int p = upper_bound(res.begin(), res.end(), a[i]) - res.begin() - 1;
    assert(p >= 0);
    int ans = (int)res.size()-p-1;
    assert(1 <= ans && ans <= h+1);
    printf("%d%c", ans, i == k-1 ? '\n' : ' ');
  }
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
