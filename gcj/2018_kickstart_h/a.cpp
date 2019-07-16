#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

string s[N];

void solve(int tc) {
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < p; ++i)
    cin >> s[i];
  vector<string> invalid;
  for (int i = 0; i < p; ++i) {
    bool ok = 1;
    for (int j = 0; j < p; ++j) {
      if (s[i].size() <= s[j].size()) continue;
      if (s[j] == s[i].substr(0, s[j].size())) {
        ok = 0;
      }
    }
    if (!ok) continue;
    invalid.push_back(s[i]);
  }
  sort(invalid.begin(), invalid.end());
  invalid.erase(unique(invalid.begin(), invalid.end()), invalid.end());
  long long ans = 1LL << n;
  for (string z : invalid) {
    int len = z.size();
    ans -= 1LL << (n - len);
  }
  printf("Case #%d: ", tc);
  printf("%lld\n", ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}