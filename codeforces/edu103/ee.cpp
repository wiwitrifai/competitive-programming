#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 5, Z = 27 * 27 * 27 * 27 + 5;
char s[N][K], p[N][K];

vector<int> superp[Z];
int ans[N], dig[K], pos[N], id[Z], din[N];

int enc(char *c, int k) {
  int cur = 0;
  for (int i = k-1; i >= 0; --i) {
    cur *= 27;
    if (c[i] == '_') continue;
    cur += c[i] - 'a' + 1;
  }
  return cur;
}

vector<int> g[N];

int combine(int u, int v, int k) {
  if (u == -1 || v == -1)
    return u + v + 1;
  int res = 0, mul = 1;
  for (int i = 0; i < k; ++i) {
    int du = u % 27;
    int dv = v % 27;
    int duv = 0;
    if (du == dv)
      duv = du;
    res += mul * duv;
    mul *= 27;
    u /= 27;
    v /= 27;
  }
  return res;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    scanf("%s", p[i]);
  for (int i = 0; i < m; ++i) {
    scanf("%s %d", s[i], pos+i);
    --pos[i];
  }
  memset(ans, -1, sizeof ans);
  int nmask = 1;
  for (int i = 0; i < k; ++i)
    nmask *= 27;
  for (int mask = 0; mask < nmask; ++mask) {
    int bmask = 0;
    int now = mask;
    for (int i = 0; i < k; ++i) {
      dig[i] = now % 27;
      if (dig[i])
        bmask |= (1 << i);
      now /= 27;
    }
    for (int curmask = bmask; ; curmask = (curmask - 1) & bmask) {
      int cur = 0;
      for (int i = k-1; i >= 0; --i) {
        cur *= 27;
        if ((curmask & (1 << i)) == 0) continue;
        cur += dig[i];
      }
      superp[mask].push_back(cur);
      if (curmask == 0)
        break;
    }
  }
  memset(id, -1, sizeof id);
  for (int i = 0; i < n; ++i) {
    int now = enc(p[i], k);
    assert(id[now] == -1);
    id[now] = i;
  }
  for (int i = 0; i < m; ++i) {
    int now = enc(s[i], k);
    int sel = enc(p[pos[i]], k);
    if (combine(now, sel, k) != sel) {
      puts("NO");
      return 0;
    }
    for (int sup : superp[now]) {
      if (sup == sel) continue;
      if (id[sup] == -1) continue;
      g[pos[i]].push_back(id[sup]);
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int u : g[i]) {
      ++din[u];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (din[i] == 0)
      ans[cnt++] = i;
  }
  for (int i = 0; i < cnt; ++i) {
    for (int u : g[ans[i]]) {
      if (--din[u] == 0) {
        ans[cnt++] = u;
      }
    }
  }
  if (cnt != n) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i] + 1, i+1 == n ? '\n' : ' ');
  return 0;
}
