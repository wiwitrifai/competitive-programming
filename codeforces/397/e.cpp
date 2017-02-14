#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n;
vector< int > g[N];

pair< int, int > selam(int u, int par = -1, int dept = 0) {
  pair< int , int > ret = {dept, u};
  for (int v : g[u]) if (v != par) {
    ret = max(ret, selam(v, u, dept+1));
  }
  return ret;
}

int c, c2, dia;
bool find(int u, int x, int par = -1, int d = 0) {
  bool ret = u == x;
  for (int v : g[u]) {
    ret |= find(v, x, u, d+1);
    if (ret)
      break;
  }
  if (ret && d == (dia+1/2))
    c = u, c2 = par;
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pair< int, int > res = selam(0);
  int a = res.second, b; 
  res = selam(a);
  b = res.second;
  dia = res.first;
  find(a, b);
  bool ok = 1;
  if (dia & 1) {
    if (!cek(c, c2) || !cek(c2, c))
      ok = 0;
  }
  else {
    if (!cek(c))
      ok = 0;
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  while ((dia & 1) == 0) dia >>= 1;
  cout << dia << endl;
  return 0;
}