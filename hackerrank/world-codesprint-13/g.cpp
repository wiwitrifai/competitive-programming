#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, S = 600, LG = 21;

int n, par[LG][N], p[N], lv[N], pos[N];
int col[N], cnt[N];

char ch[N];
int x[N], y[N], z[N];

vector<int> root;
int lca(int u, int v) {
  if (lv[u] > lv[v]) swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i)
    if (diff & (1 << i))
      v = par[i][v];
  if (u == v) return v;
  for (int i = LG-1; i >= 0; --i) {
    if (par[i][u] != par[i][v])
      u = par[i][u], v = par[i][v];
  }
  return par[0][v];
}

int naik(int u, int k) {
  int top = par[LG-1][u];
  while (col[top] + cnt[u] < k && u != 0) {
    k -= col[top] + cnt[u];
    u = p[top];
    top = par[LG-1][u];
  }
  for (int i = LG-1; i >= 0; --i) {
    if (cnt[u] - cnt[par[i][u]] < k) {
      k -= cnt[u] - cnt[par[i][u]];
      u = par[i][u];
    }
  }
  return u+1;
}

int solve(int u, int v, int k) {
  pos[0] = 1;
  sort(root.begin(), root.end());
  for (int i = 1; i < root.size(); ++i) {
    int r = root[i];
    int atas = par[LG-1][p[r]];
    pos[r] = pos[atas]+1;
  }
  int a = u, b = v;
  int le = 0, ri = 0, cntr=0;
  while (par[LG-1][a] != par[LG-1][b]) {
    if (pos[par[LG-1][a]] > pos[par[LG-1][b]])
      le += cnt[a] + col[par[LG-1][a]], a = p[par[LG-1][a]];
    else
      ri += cnt[b] + col[par[LG-1][b]], b = p[par[LG-1][b]];
  }
  int w = lca(a, b);
  le += cnt[a] - cnt[w];
  ri += cnt[b] - cnt[w];
  if (le + ri + col[w] < k)
    return -1;
  if (le + col[w] >= k) {
    return naik(u, k);
  }
  else {
    k = le + ri + col[w] + 1 - k;
    return naik(v, k);
  }
}

int main() {
  int q;
  scanf("%d", &n);
  scanf("%d", &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", col+i);
  for (int i = 1; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
  }
  for (int i = 0; i < q; ++i) {
    string str;
    cin >> str;
    ch[i] = str[0];
    if (ch[i] == 'T') {
      scanf("%d", x+i); --x[i];
    }
    else if (ch[i] == 'C') {
      scanf("%d %d", x+i, y+i);
      --x[i]; --y[i];
      assert(y[i] < x[i]);
    }
    else if (ch[i] == 'K') {
      scanf("%d %d %d", x+i, y+i, z+i);
      --x[i]; --y[i];
    }
  }
  for (int i = 0; i < q; i += S) {
    int to = min(q, i+S);
    root.clear();
    root.push_back(0);
    for (int j = i; j < to; ++j) {
      if (ch[j] == 'C' || ch[j] == 'T')
        root.push_back(x[j]);
    }
    sort(root.begin(), root.end());
    root.erase(unique(root.begin(), root.end()), root.end());
    for (int j = 0; j < n; ++j) {
      par[0][j] = p[j];
    }
    for (int v : root)
      par[0][v] = v;
    for (int v = 0; v < n; ++v) {
      for (int k = 0; k+1 < LG; ++k)
        par[k+1][v] = par[k][par[k][v]];
      if (par[0][v] != v) {
        lv[v] = lv[par[0][v]] + 1;
        cnt[v] = cnt[par[0][v]] + col[v];
      }
      else {
        lv[v] = 0;
        cnt[v] = 0;
      }
    }
    for (int j = i; j < to; ++j) {
      if (ch[j] == 'T') {
        int v = x[j];
        col[v] ^= 1;
      }
      else if (ch[j] == 'C') {
        int u = x[j], v = y[j];
        p[u] = v;
      }
      else {
        int u = x[j], v = y[j], w = z[j];
        printf("%d\n", solve(u, v, w));
      }
    }
  }
  return 0;
}