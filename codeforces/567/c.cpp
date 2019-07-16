#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  vector<tuple<int, int, int>> last;
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    vector<tuple<int, int, int>> cur;
    int it = 0;
    for (int j = 0; j < n;) {
      int r = j;
      while (r < n && s[j][i] == s[r][i]) ++r;
      int lef = j-1, rig = r;
      while (lef >= 0 && s[lef][i] == s[j-1][i]) --lef;
      while (rig < n && s[rig][i] == s[r][i]) ++rig;
      int len = r-j;
      if (j-lef-1 < len || rig - r < len) {
        j = r;
        continue;
      }
      while (it < last.size() && get<0>(last[it]) < j) ++it;
      int cnt = 1;
      if (it < last.size() && get<0>(last[it]) == j && get<1>(last[it]) == r) {
        if (s[j][i] == s[j][i-1] && s[j-1][i] == s[j-1][i-1] && s[r][i] == s[r][i-1]) {
          cnt = get<2>(last[it]) + 1;
        }
      }
      ans += cnt;
      cur.emplace_back(j, r, cnt);
      j = r;
    }
    last.swap(cur);
  }
  printf("%lld\n", ans);
  return 0;
}
