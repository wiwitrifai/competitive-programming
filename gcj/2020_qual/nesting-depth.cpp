#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int depth = 0;
  string ans;
  for (char c : s) {
    c -= '0';
    if (c > depth) {
      ans += string(c-depth, '(');
      depth = c;
    }
    else if (c < depth) {
      ans += string(depth-c, ')');
      depth = c;
    }
    ans.push_back(c+'0');
  }
  if (depth > 0)
    ans += string(depth, ')');
  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
