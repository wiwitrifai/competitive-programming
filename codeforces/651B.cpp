#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i<n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  int now = 0, ans = 0;
  for(auto it = mp.rbegin(); it != mp.rend(); it++) {
    int t = min(it->second, now);
    now += it->second - t;
    ans += t;
  }
  cout << ans << endl;
  return 0;
}