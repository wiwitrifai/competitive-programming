#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
// -1 = must small, 0 = default small, 1 = must large
int col[N];
vector<int> g[N];

bool cek(int le, int ri) {
  // cerr << le << " " << ri << " " << col[le] << " " << col[ri] << endl;
  if (col[le] == col[ri])
    return le <= ri;
  if (col[le] == 1)
    return true;
  if (col[ri] == 1)
    return false;
  return le <= ri;
}

bool toSmall(int x) {
  // cerr << x << " toSmall" << endl;
  if (col[x] == 1)
    return false;
  col[x] = -1;
  return true;
}

queue<int> que;

bool toLarge(int x) {
  // cerr << x << " toLarge" << endl;
  if (col[x] == -1)
    return false;
  if (col[x] == 0)
    que.push(x);
  col[x] = 1;
  return true;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int p, q;
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &q);
    for (int j = 0; j < q; j++) {
      scanf("%d", b+j);
    }
    if (i > 0) {
      int k = 0;
      // cerr << p << " ts " << q << endl;
      while (k < min(p, q) && a[k] == b[k]) k++; 
      if (k == min(p, q)) {
        if (k < p)
          ok = 0;
      }
      else {
        if (!cek(a[k], b[k])) {
          ok &= toLarge(a[k]);
          int last = col[b[k]];
          col[b[k]] = 1;
          bool res = cek(a[k], b[k]);
          col[b[k]] = last;
          if (!res)
            ok &= toSmall(b[k]);
        }
        g[b[k]].push_back(a[k]);
      }
    }
    p = q;
    for (int j = 0; j < p; j++)
      a[j] = b[j];
  }
  if (ok) {
    while (!que.empty() && ok) {
      int v = que.front();
      que.pop();
      for (int u : g[v]) {
        if(!cek(u, v)) {
          ok &= toLarge(u);
        }
      }
    }
  }
  if (ok) {
    puts("Yes");
    int ans = 0;
    for (int i = 1; i <= m; i++)
      ans += col[i] == 1;
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) if (col[i] == 1)
      printf("%d ", i);
    printf("\n");
  }
  else
    puts("No");
  return 0;
}