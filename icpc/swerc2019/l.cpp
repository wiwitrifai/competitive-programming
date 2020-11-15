// Unfinished

#include <bits/stdc++.h>

using namespace std;

const int N = 15;

char s[N][N];

int grund[N * N];

int cnt[N * N], edge[N * N];
int n;
int enc(int x, int y) {
  return x * n + y;
}

int find(int p[], int x) {
  return p[x] < 0 ? x : p[x] = find(p, p[x]);
}


int merge(int p[], int u, int v) {
  u = find(p, u);
  v = find(p, v);
  if (u == v) return 0;
  cnt[v] += cnt[u];
  p[u] = v;
  return 1;
}

int p[N * N], p2[N * N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  memset(p, -1, sizeof p);
  memset(p2, -1, sizeof p2);
  for (int i = 0; i < N * N; ++i) {
    set<int> st;
    for (int j = 0; j < i; ++j) {
      int lef = max(0, j-1), rig = max(i-j-2, 0);
      st.insert(grund[lef]^grund[rig]);
    }
    grund[i] = 0;
    for (int x : st)
      grund[i] += grund[i] == x;
  }

  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] != '*') continue;
      for (int k = 0; k < 4; ++k) {
        int x = i+dx[k], y = j+dy[k];
        if (min(x, y) < 0 || max(x, y) >= n) continue;
        if (s[x][y] == 'x') continue;
        merge(p, enc(i, j), enc(x, y));
        if (s[x][y] == '.')
          s[x][y] = '#';
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] != '#') continue;
      for (int k = 0; k < 4; ++k) {
        int x = i+dx[k], y = j+dy[k];
        if (min(x, y) < 0 || max(x, y) >= n) continue;
        if (s[x][y] != '#') continue;
        int u = enc(i, j), v = enc(x, u);
        if (find(p, u) != find(p, v)) continue;
        u = find(p2, u);
        v = find(p2, v);
        if (u == v) continue;
        p2[u] = v;
        edge[v] += edge[u] + 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] != '#') continue;
      ++cnt[find(p2, enc(i, j))];
    }
  }

  int ans = 0, cycle = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] != '#') continue;
      if (find(p2, enc(i, j)) != enc(i, j)) continue;
      int c = cnt[enc(i, j)], e = edge[enc(i, j)];
      if (e == c) {
        ++cycle;
        --c;
      }
      ++c;
    }
  }
  return 0;
}
