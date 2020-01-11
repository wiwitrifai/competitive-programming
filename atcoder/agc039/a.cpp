#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];

int main() {
  int k;
  scanf("%s %d", s, &k);
  int n = strlen(s);
  vector<pair<int, char>> groups;
  char last = s[0];
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (last != s[i]) {
      groups.emplace_back(cnt, last);
      cnt = 0;
      last = s[i];
    }
    ++cnt;
  }
  groups.emplace_back(cnt, last);
  if (groups.size() == 1) {
    long long tot = 1LL * n * k;
    printf("%lld\n", tot / 2);
    return 0;
  }
  long long ans = 0;
  if (groups[0].second == groups.back().second) {
    for (int i = 1; i + 1 < (int)groups.size(); ++i) {
      ans += groups[i].first / 2;
    }
    ans *= k;
    ans += groups[0].first / 2 + groups.back().first / 2;
    ans += 1LL * (k-1) * ((groups[0].first + groups.back().first) / 2);
  }
  else {
    for (auto it : groups) {
      ans += it.first / 2;
    }
    ans *= k;
  }
  printf("%lld\n", ans);
  return 0;
}
