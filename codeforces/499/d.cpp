#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N][5];

int a[N], b[N];
int val[N], ans[N];

int calc(int v) {
  if (s[v][0] == 'I') {
    val[v] = a[v];
  }
  else if (s[v][0] == 'N') {
    val[v] = !calc(a[v]);
  }
  else if (s[v][0] == 'A') {
    val[v] = calc(a[v]) & calc(b[v]);
  }
  else if (s[v][0] == 'O') {
    val[v] = calc(a[v]) | calc(b[v]);
  }
  else {
    assert(s[v][0] == 'X');
    val[v] = calc(a[v]) ^ calc(b[v]);
  }
  return val[v];
}

void dfs(int v) {
  if (s[v][0] == 'I') {
    ans[v] ^= 1;
  }
  else if (s[v][0] == 'N') {
    dfs(a[v]);
  }
  else if (s[v][0] == 'A') {
    if (((!val[a[v]]) & val[b[v]]) != val[v])
      dfs(a[v]);
    if (((!val[b[v]]) & val[a[v]]) != val[v])
      dfs(b[v]);
  }
  else if (s[v][0] == 'O') {
    if (((!val[a[v]]) | val[b[v]]) != val[v])
      dfs(a[v]);
    if (((!val[b[v]]) | val[a[v]]) != val[v])
      dfs(b[v]);
  }
  else {
    assert(s[v][0] == 'X');
    if (((!val[a[v]]) ^ val[b[v]]) != val[v])
      dfs(a[v]);
    if (((!val[b[v]]) ^ val[a[v]]) != val[v])
      dfs(b[v]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i]);
    scanf("%d", a+i);
    if (s[i][0] == 'A' || s[i][0] == 'O' || s[i][0] == 'X')
      scanf("%d", b+i);
  }
  calc(1);
  for (int i = 1; i <= n; ++i)
    ans[i] = val[1];
  dfs(1);
  for (int i = 1; i <= n; ++i)
    if (s[i][0] == 'I')
      printf("%d", ans[i]);
  printf("\n");
  return 0;
}