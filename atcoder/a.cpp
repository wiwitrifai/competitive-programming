#include <bits/stdc++.h>

using namespace std;

int r, c, dx[] = {0, 0, -1, -1}, dy[] = {0, -1, 0, -1}, val[] = {1, 2, 4, 8};
map< pair<int, int>, long long > mp;
map< pair<int, int>, long long > cnt;

int main() {
  scanf("%d %d", &r, &c);
  int n;
  scanf("%d", &n);
  queue< pair<int, int > > q;
  for (int i = 0; i < n; i++) {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);
    mp[{a, b}] = v;
    for (int j = 0; j < 4; j++) {
        if (a + dx[j] > 0 && b + dy[j] > 0) {
          int x = a + dx[j], y = b + dy[j];
          cnt[{x, y}] |= val[j];
          if (__builtin_popcount(cnt[{x, y}]) > 2) {
            q.push({x, y});
          }
        }
      }
  }
  bool ok = true;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    int v = cnt[{x, y}];
    if (v == 15) {
      ok &= (mp[{x, y}] + mp[{x+1, y+1}]) == (mp[{x+1, y}] + mp[{x, y+1}]);
      // cerr << mp[{x, y}] + mp[{x+1, y+1}] <<  " " << (mp[{x+1, y}] == mp[{x, y+1}<< endl;
      if (!ok)
        break;
    }
    else {
      long long sum = 0;
      for (int i = 0; i < 4; i++)
        if (v & (1<<i))
          sum += mp[{x - dx[i], y - dy[i]}];
      for (int i = 0; i < 4; i++)
        if (!(v & (1<<i))) {
          long long should = sum - 2 * mp[{x - dx[3-i], y-dy[3-i]}];
          if (should < 0) {
            ok = false;
            break;
          }
          if (mp.count({x-dx[i], y-dy[i]})) {
            ok &= should == mp[{x-dx[i], y-dy[i]}];
          }
          else {
            int a = x-dx[i], b = y-dy[i];
            mp[{a, b}] = should;
            for (int j = 0; j < 4; j++) {
              if (a + dx[j] > 0 && b + dy[j] > 0) {
                int xx = a + dx[j], yy = b + dy[j];
                cnt[{xx, yy}] |= val[j];
                if (__builtin_popcount(cnt[{xx, yy}]) > 2) {
                  q.push({xx, yy});
                }
              }
            }         
          }
        }
      if (!ok)
        break;
    }
  }
  puts(ok ? "Yes" : "No");
  return 0;
}