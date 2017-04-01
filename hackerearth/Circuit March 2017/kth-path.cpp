#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n, m;
string s[N];
long long k;
map< pair< int, int >, long long > mp[2][30];
long long C(long long w, long long x, long long y, long long z) {
  long long cur = w;
  if (cur == 0) return 0;
  if (cur >= z)
    return 0;
  y = min(y, x-y);
  for (int i = 0; i < y; i++) {
    if ((double)cur * (x-i)/(i+1) >= (double)z)
      return 0;
    cur = cur * (x-i)/(i+1);
  }
  return z-cur;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++)
      s[i][j] -= 'a';
  }
  scanf("%lld", &k);
  long long wew = C(1, n+m-2, n-1, k);
  if (wew > 0) {
    puts("-1");
    return 0;
  }
  int c = 0, b = 1;
  mp[c][s[0][0]][make_pair(0, 0)] = 1;
  string res = "";
  bool ok = 1;
  for (int iter = 0; iter < n+m-1; iter++) {
    swap(c, b);
    for (int i = 0; i < 26; i++)
      mp[c][i].clear();
    int ans = 25;
    while (ans > 0 && mp[b][ans].empty()) ans--;
    for (int i = 0; i < 26; i++) {
      long long cur = k;
      for (auto it : mp[b][i]) {
        cur = C(it.second, n+m-2-it.first.first-it.first.second, n-1-it.first.first, cur);
      }
      if (ans == i)
        break;
      if (cur <= 0) {
        ans = i;
        break;
      }
      else
        k = cur;
    }
    res += char(ans+'a');
    for (auto it : mp[b][ans]) {
      int xx = it.first.first, yy = it.first.second;
      long long cur = min(it.second, k + 1);
      if (xx + 1 < n) {
        xx++;
        mp[c][s[xx][yy]][make_pair(xx, yy)] += cur;
        xx--;
      }
      if (yy + 1 < m) {
        yy++;
        mp[c][s[xx][yy]][make_pair(xx, yy)] += cur;
        yy--;
      }
    }
  }
  if (ok)
    cout << res << endl;
  else
    puts("-1");
  return 0;
}