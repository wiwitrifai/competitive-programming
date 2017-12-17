#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    mp[a]++;
  }
  long long ans = 0;
  for (auto it : mp) {
    if (it.first <= it.second)
      ans += it.second - it.first;
    else
      ans += it.second;
  }
  cout << ans << endl;
  return 0;
}