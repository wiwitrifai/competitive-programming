#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, r, s, k;
vector< int > child[N];
char str[N];
long long fill[N];
bool path[N];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

long long revs(long long val) {
  long long ret = 0;
  for (int i = 0; i <= k; i++)
    if (val & (1LL<<i))
      ret |= (1LL<<(k-1-i));
  return ret;
}
void dfs(int v) {
  if ((v % s) == 0)
    path[v] = 1;
  fill[v] = 0;
  for (int u : child[v]) {
    dfs(u);
    if (!path[u]) continue;
    path[v] = 1;
    long long rev = revs(fill[v]);
    fill[v] = 0;
    for (int j = 0; j <= k; j++) {
      fill[v] |= ((revs >> j) & fill[u]) ? (1LL << (k-j)) : 0;
    }
  }
  if (path[v])
    fill[v] |= 2;
}

int main() {
  scanf("%d %d %d", &r, &s, &k);
  n = r * s;
  for (int i = 0; i < r; i++) {
    scanf("%s", str);
    for (int j = 0; j < s; j++) {
      int par = 0;
      if (s[j] == 'D')
        par = (i + 1) * s + j;
      else if (s[j] == 'L')
        par = i * s + j - 1;
      else if (s[j] == 'R')
        par = i * s + j + 1;
      else
        par = (i-1) * s + j;
      if (j == s-1)
        par = n;
      child[par].push_back(i * s + j);
    }
  } 
  dfs(n);
  int cnt = n;
  for (int i = 0; i < n; i++)
    if (path[i])
      cnt--;
  bool 
  for (int i = 2; i <= k; i++) {

  }
  return 0;
}