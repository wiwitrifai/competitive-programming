#include <bits/stdc++.h>

using namespace std;

const int N = 202;

int created[N], n, m;

int u2u[N][N], u2s[N][N];

int ma[N][N], mb[N][N];

int calc_a(int u, int v) {
  int & ret = ma[u][v];
  if (ret != -1)
    return ret;
  if (u == v) {
    return ret = 0;
  }
  if (u2u[u][v]) {
    return ret = 3;
  }
  for (int i = 0; i < n; ++i) {
    if (u2s[u][i] && created[i] == v)
      return ret = 2;
  }
  for (int i = 0; i < n; ++i) {
    if (u2s[u][i] && u2s[v][i])
      return ret = 1;
  }
  return ret = 0;
}

int calc_b(int u, int s) {
  int & ret = mb[u][s];
  if (ret != -1)
    return ret;
  if (created[s] == u)
    return ret = 2;
  if (u2s[u][s])
    return ret = 1;
  return ret = 0;
}

int main() {
  memset(ma, -1, sizeof ma);
  memset(mb, -1, sizeof mb);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", created+i), --created[i];
  int p, q;
  scanf("%d %d", &p, &q);
  for (int i = 0; i < p; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    u2u[u][v] = 1;
  }
  for (int i = 0; i < q; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    u2s[u][v] = 1;
  }
  vector<pair<int, int>> stories(n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int score = 0;
      if (created[j] == i || u2s[i][j]) {
        score = -1;
      } else {
        for (int k = 0; k < m; ++k) {
          score += calc_a(i, k) * calc_b(k, j);
        }
      }
      stories[j] = {-score, j};
    }
    sort(stories.begin(), stories.end());
    for (int j = 0; j < 3; ++j) {
      printf("%d%c", stories[j].second + 1, j == 2 ? '\n' : ' ');
    }
  }
  return 0;
}
