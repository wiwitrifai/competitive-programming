#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int p[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  if((u = find(u)) == (v = find(v)))
    return;
  if(p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i<=n; i++)
      p[i] = -1;
    for(int i = 0; i<m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      merge(a, b);
    }
    vector< int > sz;
    for(int i = 1; i<=n; i++) {
      if(p[i] < 0)
        sz.push_back(-p[i]);
    }
    sort(sz.begin(), sz.end());
    int sum = 0;
    for(int i = (int)sz.size()-1; i>=0 && k--> 0; i--) {
      sum += sz[i];
    }
    puts(sum >= q ? "Satisfied" : "Unsatisfied");
  }
  
  return 0;
}