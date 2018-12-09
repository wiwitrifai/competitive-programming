#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 1e5 + 5, C = 26;

string s[N];
char buffer[N];
vector<int> a[N];
int ch[N][C], par[N], dep[N], cnt[N];

int nodes = 0;
int new_nodes(int lv) {
  ++nodes;
  memset(ch[nodes], 0, sizeof ch[nodes]);
  par[nodes] = 1;
  dep[nodes] = lv;
  cnt[nodes] = 0;
  return nodes;
}
int q[N];
long long best[N];

int main() {
  open_file("exciting.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", buffer);
      s[i] = buffer;
    }
    for (int i = 0; i < n; ++i) {
      a[i].resize(s[i].size());
      for (int j = 0; j < s[i].size(); ++j)
        scanf("%d", &a[i][j]);
    }
    nodes = 0;
    new_nodes(0);
    for (int i = 0; i < n; ++i) {
      int now = 1;
      for (int j = 0; j < s[i].size(); ++j) {
        s[i][j] -= 'a';
        int c = s[i][j];
        if (!ch[now][c])
          ch[now][c] = new_nodes(j+1);
        now = ch[now][c];
        ++cnt[now];
      }
    }
    int nq = 0;
    for (int i = 0; i < C; ++i)
      if (ch[1][i])
        q[nq++] = ch[1][i];
    for (int i = 0; i < nq; ++i) {
      int v = q[i];
      for (int c = 0; c < C; ++c) {
        int u = ch[v][c];
        if (u == 0) continue;
        int p = par[v];
        while (p > 1 && !ch[p][c]) p = par[p];
        if (ch[p][c]) p = ch[p][c];
        par[u] = p;
        q[nq++] = u;
      }
    }
    best[1] = 0;
    for (int i = 0; i < nq; ++i) {
      int v = q[i];
      best[v] = max(best[par[v]], 1LL * dep[v] * cnt[v]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int now = 1;
      for (int j = 0; j < s[i].size(); ++j) {
        now = ch[now][s[i][j]];
        ans = max(ans, best[now] * a[i][j]);
      }
    }
    printf("%lld\n", ans);
  }
  close_file();
  return 0;
}