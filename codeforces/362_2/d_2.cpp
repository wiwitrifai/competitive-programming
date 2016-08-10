#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, p[N], sz[N];
vector< int > ch[N];
double ans[N];

int get_size(int v) {
  sz[v] = 1;
  for(int u : ch[v])
    sz[v] += get_size(u);
  return sz[v];
}

void solve(int v) {
  int sum = sz[v] - 1;
  for(int u : ch[v]) {
    ans[u] = (double)(sum - sz[u])/2.0 + ans[v] + 1.0;
    solve(u);
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i<n; i++) {
    scanf("%d", p+i);
    p[i]--;
    ch[p[i]].push_back(i);
  }
  get_size(0);
  ans[0] = 1;
  solve(0);
  for(int i = 0; i<n; i++)
    printf("%.1lf ", ans[i]);
  printf("\n");
  return 0;
}