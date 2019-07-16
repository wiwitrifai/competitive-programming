#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int s[N], h[N];
int a[N];
bool used[N];
int id[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d %d", s+i, h+i), id[s[i]] = i;
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  for (int p = 1; p <= n; ++p) {
    memset(used, 0, sizeof used);
    int l = 1, r = n;
    while (l <= p && id[l] == 0) ++l;
    while (r > p && id[r] == 0) --r;
    if (l > p) continue;
    bool ok = 1;
    int now = 0;
    for (int i = l; i <= p; ++i) {
      if (id[i] && now < h[id[i]]) {
        used[i] = 1;
        now = h[id[i]];
      }
      now += a[i];
      if (now < 0) {
        ok = 0;
        break;
      }
    }
    if (!ok) continue;
    now = 0;
    for (int i = r; i > p; --i) {
      if (id[i] && now < h[id[i]]) {
        used[i] = 1;
        now = h[id[i]];
      }
      now += a[i];
      if (now < 0) {
        ok = 0;
        break;
      }
    }
    if (!ok) continue;
    printf("%d\n", p);
    vector<int> ans;
    for (int i = p; i > 0; --i) {
      if (!used[i]) continue;
      ans.push_back(id[i]);
    }
    for (int i = p+1; i <= n; ++i) {
      if (!used[i]) continue;
      ans.push_back(id[i]);
    }
    for (int i = 1; i <= n; ++i) {
      if (used[i]) continue;
      if (id[i] == 0) continue;
      ans.push_back(id[i]);
    }
    assert(ans.size() == m);
    for (int i = 0; i < m; ++i)
      printf("%d%c", ans[i], i == m-1 ? '\n' : ' ');
    return 0;
  }
  puts("-1");
  return 0;
}