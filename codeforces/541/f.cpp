#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> e[N];
int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  assert( ((u = find(u)) != (v = find(v))) );
  if (-p[u] > -p[v])
    swap(u, v);
  for (int x : e[u])
    e[v].push_back(x);
  p[v] += p[u];
  p[u] = v;
}

int main() {
  memset(p, -1, sizeof p);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    e[i].push_back(i);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    merge(u, v);
  }
  int r = find(1);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", e[r][i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}