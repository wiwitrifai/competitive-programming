#include <bits/stdc++.h>

using namespace std;

map< pair<int, int>, int > mp;
pair<int, int> p[2016];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = {x, y};
  }
  sort(p, p+n);
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<i; j++) {
      pair<int, int> diff = {p[i].first - p[j].first, p[i].second - p[j].second};
      if(mp.count(diff))
        ans += mp[diff];
    }
    for(int j = 0; j<i; j++) {
      pair<int, int> diff = {p[i].first - p[j].first, p[i].second - p[j].second};
      mp[diff]++;
    }
  }
  cout << ans/2 << endl;
  return 0;
}