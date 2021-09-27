#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  long long a, b;
  cin >> n >> m >> a >> b;
  int len = n + m - 1;
  if (min(a, b) < len) {
    puts("Impossible");
    return;
  }
  vector<vector<int>> ans(n, vector<int>(m, 1000));
  for (int i = 0; i < n; ++i) {
    ans[i][0] = ans[i][m-1] = 1;
  }
  for (int i = 0; i < m; ++i) {
    ans[0][i] = 1;
  }
  ans[n-1][m-1] = a - (len - 1);
  ans[n-1][0] = b - (len - 1);
  puts("Possible");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d%c", ans[i][j], j+1 == m ? '\n' : ' ');
    }
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
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
