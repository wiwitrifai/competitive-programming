#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<string> s(n);
  for (int i = 0; i < n; ++i)
    cin >> s[i];
  set<vector<pair<int, int>>> ans;
  constexpr int inf = 1e9 + 7;
  int best = inf;
  for (int i = 0; i < n; ++i) {
    bool exist = 0;
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'O') {
        exist = true;
        break;
      }
    }
    if (exist) continue;
    vector<pair<int, int>> v;
    for (int j = 0; j < n; ++j) {
      if (s[i][j] == 'X') continue;
      v.emplace_back(i, j);
    }
    if ((int)v.size() < best) {
      ans.clear();
      ans.insert(v);
      best = v.size();
    } else if ((int)v.size() == best) {
      ans.insert(v);
    }
  }
  for (int j = 0; j < n; ++j) {
    bool exist = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == 'O') {
        exist = true;
        break;
      }
    }
    if (exist) continue;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == 'X') continue;
      v.emplace_back(i, j);
    }
    if ((int)v.size() < best) {
      ans.clear();
      ans.insert(v);
      best = v.size();
    } else if ((int)v.size() == best) {
      ans.insert(v);
    }
  }
  if (best >= inf) {
    puts("Impossible");
  } else {
    printf("%d %d\n", best, (int)ans.size());
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
