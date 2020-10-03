#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<pair<int, int>> all;
  int a = 0, c = 0;
  all.emplace_back(a, c);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      ++a;
    } else if (s[i] == 'T') {
      --a;
    } else if (s[i] == 'C') {
      ++c;
    } else {
      --c;
    }
    all.emplace_back(a, c);
  }
  sort(all.begin(), all.end());
  long long ans = 0;
  for (int i = 0; i < (int)all.size();) {
    int j = i+1;
    while (j < (int)all.size() && all[j] == all[i]) ++j;
    int cnt = j - i;
    ans += 1LL * cnt * (cnt - 1) / 2;
    i = j;
  }
  printf("%lld\n", ans);
  return 0;
}
