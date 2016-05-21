#include <bits/stdc++.h>

using namespace std;

int n;
map<int, int> mx, my;
map< pair<int, int >, int > mxy;

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    mxy[{x, y}]++;
    mx[x]++;
    my[y]++;
  }
  long long ans = 0;
  for(auto it = mx.begin(); it != mx.end(); it++) {
    ans += 1LL*(it->second) * (it->second - 1)/2;
  }
  for(auto it = my.begin(); it != my.end(); it++) {
    ans += 1LL*(it->second) * (it->second - 1)/2;
  }
  for(auto it = mxy.begin(); it != mxy.end(); it++) {
    ans -= 1LL*(it->second) * (it->second - 1)/2;
  }
  cout << ans << endl;
  return 0;
}