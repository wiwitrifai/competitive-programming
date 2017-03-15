#include <bits/stdc++.h>

using namespace std;
void openfile(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}
void closefile() {
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
}

const int N = 1<<18, inf = 1e8 + 9;
int len[N], rmq[(N << 1) + 10], a[N], b[N], n, m, k, q, col[N], live[N];

void upd(int x, int val) {
  for (x += N; x; x >>= 1)
    rmq[x] = x >= N ? val : min(rmq[x+x], rmq[x+x+1]);
}
vector< int > edge[N];


int main() {
  openfile("grass");
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 0; i < (N << 1); i++) {
    rmq[i] = inf;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", a+i, b+i, len+i);
    a[i]--; b[i]--;
    edge[a[i]].push_back(i);
    edge[b[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", col+i);
  }
  for (int i = 0; i < m; i++) {
    if (col[a[i]] != col[b[i]])
      upd(i, len[i]), live[i] = 1;
    else
      live[i] = 0;
  }
  while (q--) {
    int v, nc;
    scanf("%d %d", &v, &nc);
    v--;
    col[v] = nc;
    for (int e : edge[v]) {
      if (col[a[e]] != col[b[e]]) {
        if (!live[e])
          upd(e, len[e]), live[e] = 1;
      }
      else {
        if (live[e])
          upd(e, inf), live[e] = 0;
      }
    }
    printf("%d\n", rmq[1]);
  }
  closefile();
  return 0;
}