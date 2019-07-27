#include <bits/stdc++.h>

using namespace std;

const int N = 4040;

int h, n;
vector<pair<int,int>> laser;

void read_input() {
  scanf("%d %d", &h, &n);
  laser.resize(n);
  for (int i = 0; i < n; ++i) {
    int x, c;
    scanf("%d %d", &x, &c);
    --c;
    laser[i] = {x, c};
  }
  sort(laser.begin(), laser.end());
}


int cost[N][N];
int dp[N];

void solve() {
  for (int i = 0; i < n; ++i) {
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int j = i; j < n; ++j) {
      int c = laser[j].second;
      ++cnt[c];
      cost[i][j] = 0;
      for (int k = 0; k < 2; ++k) {
        cost[i][j] = max(cost[i][j], cnt[k] * (cnt[k]-1) / 2);
      }
    }
  }
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i+1] = 0;
    for (int j = 0; j <= i; ++j) {
      dp[i+1] = max(dp[i+1], dp[j] + cost[j][i]);
    }
  }
  printf("%d\n", dp[n]);
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
