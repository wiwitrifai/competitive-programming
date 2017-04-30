#include <bits/stdc++.h>

using namespace std;

const int N = 15e4 + 5, inf = 1e9 + 7;

int d[N][10], n;
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    n = strlen(s);
    queue< pair< int, int > > que;
    int bg = 0;
    for (int i = 0; i < n; i++) {
      s[i] -= '0';
      bg = max(bg, (int)s[i]);
      for (int j = 0; j <= s[i]; j++)
        d[i][j] = 0;
      for (int j = s[i]+1; j < 10; j++)
        d[i][j] = inf;
      que.push(make_pair(i, s[i]));
    }
    while (!que.empty()) {
      int v = que.front().first, c = que.front().second;
      que.pop();
      int val = d[v][c] + 1;
      for (int i = max(0, v-9); i < min(v+10, n); i++) {
        int x = abs(i-v);
        int cur = -1;
        for (int j = 0; j <= c; j++)
          if (d[i][j] < val) {
            cur = max(cur, j);
          }
        if (cur == -1) continue;
        if (c - cur < x) continue;
        if (d[i][c] > val) {
          for (int j = 0; j <= c; j++)
            d[i][j] = min(d[i][j], val);
          que.push(make_pair(i, c));
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, d[i][bg]);
    printf("%d\n", ans);
  } 
  return 0;
}