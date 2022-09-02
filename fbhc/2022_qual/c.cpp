#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  vector<string> s(1);
  cin >> n >> s[0];
  auto backtrack = [&](auto& self, string cur, int len) {
    if ((int)s.size() >= n) return;
    if ((int)cur.size() == len) {
      s.push_back(cur);
      return;
    }
    cur.push_back('.');
    self(self, cur, len);
    cur.back() = '-';
    self(self, cur, len);
  };
  backtrack(backtrack, s[0][0] == '.' ? "-" : ".", 10);
  assert((int)s.size() == n);
  cout << "\n";
  for (int i = 1; i < n; ++i) {
    cout << s[i] << '\n';
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
