#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N][13];
map<string, int> st;

int batas[4];
int cnt[N][4];
int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return false;
  bool ok = 1;
  for (int i = 0; i < 4; ++i) {
    ok &= (cnt[u][i] + cnt[v][i]) <= batas[i];
  }
  if (!ok) return false;
  if (-p[v] < -p[u]) swap(u, v);
  for (int i = 0; i < 4; ++i)
    cnt[v][i] += cnt[u][i];
  p[v] += p[u];
  p[u] = v;
  return true;
}

int main() {
  int n, m, l;
  scanf("%d %d %d", &n, &m, &l);
  for (int i = 0; i < 4; ++i)
    scanf("%d", batas+i);
  for (int i = 0; i < n; ++i) {
    int g;
    scanf("%s %d", s[i], &g);
    st[s[i]] = i;
    cnt[i][g] = 1;
    cnt[i][0] = 1;
  }
  memset(p, -1, sizeof p);
  for (int i = 0; i < m; ++i) {
    char su[13], sv[13];
    int u, v;
    scanf("%s %s", su, sv);
    u = st[su];
    v = st[sv];
    merge(u, v);
  }
  int ma = 0;
  for (int i = 0; i < n; ++i)
    ma = max(ma, cnt[i][0]);
  if (ma < l) {
    puts("no groups");
    return 0;
  }
  vector<string> ans;
  for (int i = 0; i < n; ++i) {
    if (cnt[find(i)][0] == ma)
      ans.push_back(s[i]);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i)
    printf("%s\n", ans[i].c_str());
  return 0;
}