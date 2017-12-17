#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int l[N * 4], r[N * 4];

long long f(long long x) {
  return x & -x;
}

char s[N];

long long dfs(int v, long long d) {
  if (!l[v] && !r[v]) return 0;
  long long ret = 0;
  if (l[v])
    ret ^= dfs(l[v], d-1);
  else
    ret ^= f(d);
  if (r[v])
    ret ^= dfs(r[v], d-1);
  else
    ret ^= f(d);
  return ret;
}

int main() {
  memset(l, 0, sizeof l);
  memset(r, 0, sizeof r);
  int nodes = 1;
  int root = 1;
  int n;
  long long x;
  scanf("%d %lld", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    int now = root;
    for (int j = 0; j < len; ++j) {
      if (s[j] == '0') {
        if (!l[now])
          l[now] = ++nodes;
        now = l[now];
      }
      else {
        if (!r[now])
          r[now] = ++nodes;
        now = r[now];
      }
    }
  }
  puts(dfs(root, x) ? "Alice" : "Bob"); 
  return 0;
}