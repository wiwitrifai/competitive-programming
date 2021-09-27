#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  string p;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'F') continue;
    p.push_back(s[i]);
  }
  int ans = 0;
  for (int i = 0; i + 1 < (int)p.size(); ++i) {
    ans += p[i] != p[i+1];
  }
  cout << ans << endl;
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
