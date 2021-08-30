#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  int k;
  cin >> s >> k;
  vector<vector<int>> g(26, vector<int>(26, -1));
  for (int i = 0; i < k; ++i) {
    char a, b;
    cin >> a >> b;
    g[a-'A'][b-'A'] = 1;
  }
  for (int i = 0; i < 26; ++i)
    g[i][i] = 0;
  for (int z = 0; z < 26; ++z) {
    for (int i = 0; i < 26; ++i) {
      if (g[i][z] < 0) continue;
      for (int j = 0; j < 26; ++j) {
        if (g[z][j] < 0) continue;
        int res = g[i][z] + g[z][j];
        if (g[i][j] < 0 || g[i][j] > res)
          g[i][j] = res;
      }
    }
  }
  int ans = -1;
  for (int c = 0; c < 26; ++c) {
    int cur = 0;
    for (char b : s) {
      b -= 'A';
      if (g[b][c] < 0) {
        cur = -1;
        break;
      }
      cur += g[b][c];
    }
    if (cur < 0) continue;
    if (ans < 0 || ans > cur) {
      ans = cur;
    }
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
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
