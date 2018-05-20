#include <bits/stdc++.h>

using namespace std;

char s[101];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    priority_queue<int> pq;
    int d;
    scanf("%d %s", &d, s);
    int len = strlen(s);
    long long cur = 0; 
    for (int i = 0, j = 0; i < len; ++i) {
      if (s[i] == 'C')
        ++j;
      else {
        if (j)
          pq.push(j);
        cur += 1 << j;
      }
    }
    int ans = 0;
    while (cur > d && !pq.empty()) {
      int v = pq.top(); pq.pop();
      ++ans;
      cur -= 1 << v;
      --v;
      cur += 1 << v;
      if (v)
        pq.push(v);
    }
    if (cur > d)
      printf("Case #%d: IMPOSSIBLE\n", tc);
    else
      printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}