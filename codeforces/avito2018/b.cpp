#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, x;
    scanf("%d %d", &a, &x);
    mp[a] = max(mp[a], x);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, x;
    scanf("%d %d", &a, &x);
    mp[a] = max(mp[a], x);
  }
  long long ans = 0;
  for (auto it : mp)
    ans += it.second;
  printf("%lld\n", ans);
  return 0;
}