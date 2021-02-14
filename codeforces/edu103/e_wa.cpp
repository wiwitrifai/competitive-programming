// I misunderstood the problem:
// I thought that s[i] had to match p'[mt[i]], where p'[1..N] are the patterns after rearrangement.

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 5, Z = 27 * 27 * 27 * 27 + 5;
char s[N][K], p[N][K];

vector<int> superp[Z];
int st[Z], ans[N], dig[K], pos[N], id[Z], match[N];

int enc(char *c, int k) {
  int cur = 0;
  for (int i = k-1; i >= 0; --i) {
    cur *= 27;
    if (c[i] == '_') continue;
    cur += c[i] - 'a' + 1;
  }
  return cur;
}

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
  memset(match, -1, sizeof match);
  for (int i = 0; i < m; ++i) {
    int now = enc(s[i], k);
    for (int sup : superp[now]) {
      assert(combine(sup, now, k) == sup);
      st[sup] = max(st[sup], pos[i]);
    }
    match[pos[i]] = combine(match[pos[i]], now, k);    
  }
  for (int i = 0; i < n; ++i) {
    int now = enc(p[i], k);
    assert(id[now] == -1);
    id[now] = i;
  }
  for (int i = 0; i < nmask; ++i) {
    if (id[i] == -1) continue;
    int x = st[i];
    if (ans[x] == -1 && combine(match[x], i, k) == i) {
      ans[x] = id[i];
      id[i] = -1;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (ans[pos[i]] == -1) {
      puts("NO");
      return 0;
    }
  }
  vector<pair<int, int>> all;
  for (int i = 0; i < nmask; ++i) {
    if (id[i] == -1) continue;
    all.emplace_back(st[i], id[i]);
  }
  sort(all.rbegin(), all.rend());
  for (int i = 0; i < n; ++i) {
    if (ans[i] != -1) continue;
    if (all.back().first > i) {
      puts("NO");
      return 0;
    }
    ans[i] = all.back().second;
    all.pop_back();
  }
  puts("YES");
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i] + 1, i+1 == n ? '\n' : ' ');
  return 0;
}
