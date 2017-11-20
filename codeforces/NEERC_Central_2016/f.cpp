#include <bits/stdc++.h>

using namespace std;

const int N = 1050;

vector<int> heavier[N], lighter[N], same[N];
char col[N];

queue<int> q;

void upd(int u, char c) {
  if (col[u]) {
    if (col[u] != c) {
      col[u] = '?';
      q.push(u);
    }
  }
  else {
    col[u] = c;
    q.push(u);
  }
}

void relax(int v) {
  if (col[v] == 'R') {
    for (int u : same[v])
      upd(u, 'R');
    for (int u : heavier[v])
      upd(u, 'W');
    for (int u : lighter[v])
      upd(u, 'B');
  }
  else {
    for (int u : same[v])
      upd(u, col[v]);
  }
}

char s[N];

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  if (-p[u] < -p[v])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    scanf("%s", s);
    u = 0;
    int len = strlen(s);
    int ic = 0;
    while (ic < n && s[ic] >= '0' && s[ic] <= '9') ic++;
    u = stoi(string(s, s+ic));
    v = stoi(string(s+ic+1, s+n));
    if (s[ic] == '=') {
      same[u].push_back(v);
      same[v].push_back(u);
    }
    else {
      if (s[ic] == '>')
        swap(u, v);
      heavier[u].push_back(v);
      lighter[v].push_back(u);
    }
  }
  memset(p, -1, sizeof p);
  for (int i = 1; i <= n; i++) {
    for (int u : same[i])
      merge(i, u);
  }
  for (int i = 1; i <= n; i++) {
    int v = find(i);
    if (v != i) {
      for (int u : heavier[i])
        heavier[v].push_back(u);
      for (int u : lighter[i])
        lighter[v].push_back(u);
    }
  }
  for (int i = 1; i <= n; i++)
    if (heavier[i].size() > 0 && lighter[i].size() > 0)
      upd(i, 'R');
  while (!q.empty()) {
    int v = q.front(); q.pop();
    relax(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!col[i]) col[i] = '?';
  }
  col[n+1] = '\0';
  printf("%s\n", col + 1); 
  return 0;
}