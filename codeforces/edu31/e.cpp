#include <bits/stdc++.h>

using namespace std;

const int M = 1 << 14;

int p[M << 1];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (p[u] < p[v])
    swap(u, v);
  p[u] = v;
}

char s[2][M];

int deco(char c) {
  if ('0' <= c && c <= '9')
    return c - '0';
  return c - 'A' + 10;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int c = 1, b = 0;
  for (int i = 0; i < m; i++)
    s[c][i] = '0';
  int ans = 0;
  for (int i = 0; i < n; i++) {
    swap(c, b);
    scanf("%s", s[c]);
    fill(p + c * m, p + c * m + m, -1-i);
    int last = 0;
    for (int j = 0; j < m; j++) {
      int id = j >> 2, r = 3 - (j & 3);
      int now = deco(s[c][id]);
      if (now & (1 << r)) {
        int up = deco(s[b][id]) & (1 << r);
        if (up)
          merge(j, j+m);
        if (last)
          merge(j + c * m, j + c * m -1);
        last = 1;
      }
      else
        last = 0;
    }
    for (int j = 0; j < m; j++) {
      int id = j >> 2, r = 3 - (j & 3);
      if ((deco(s[b][id]) & (1 << r)) && p[j + b * m] < 0)
        ans++;
    }
  }  
  for (int j = 0; j < m; j++) {
    int id = j >> 2, r = 3 - (j & 3);
    if ((deco(s[c][id]) & (1 << r)) && p[j + c * m] < 0)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}