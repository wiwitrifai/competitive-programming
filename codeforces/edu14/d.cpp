#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector< int > id[N], val[N];
int a[N], p[N];

int find(int x) {
  return (p[x] < 0) ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if((u = find(u)) == (v = find(v)))
    return;
  if(p[v] < p[u])
    swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  memset(p, -1, sizeof p);
  while(m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    merge(u, v);
  }
  for(int i = 0; i<n; i++) {
    int x = find(i);
    id[x].push_back(i); 
    val[x].push_back(a[i]);
  }
  for(int i = 0; i<n; i++) {
    sort(id[i].begin(), id[i].end());
    sort(val[i].begin(), val[i].end());
    for(int j = 0; j<id[i].size(); j++) {
      a[id[i][j]] = val[i][(int)id[i].size() - j - 1];
    }
  }
  for(int i = 0; i<n; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}