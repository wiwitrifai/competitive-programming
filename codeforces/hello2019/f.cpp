#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, V = 7001;

bitset<V> bs[N], pre[V], mask[V];
int pr[N], mob[N];

int main() {
  for (int i = 1; i < V; ++i) {
    for (int j = i; j < V; j += i)
      pre[j][i] = 1;
  }
  for (int i = 2; i < V; ++i) {
    if (pr[i]) continue;
    for (int j = i; j < V; j += i)
      if (pr[j] == 0)
        pr[j] = i;
  }
  mob[1] = 1;
  for (int i = 2; i < V; ++i) {
    int now = i;
    int p = pr[i];
    int cnt = 0;
    while ((now % p) == 0) {
      now /= p;
      ++cnt;
    }
    if (cnt > 1)
      mob[i] = 0;
    else
      mob[i] = -mob[now];
  }
  vector<int> nzero;
  for (int i = 1; i < V; ++i)
    if (mob[i])
      nzero.push_back(i);
  for (int i = 1; i < V; ++i) {
    for (int u : nzero) {
      if (i * u >= V) break;
      mask[i][i * u] = 1;
    }
  }
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < q; ++i) {
    int t, a, b;
    scanf("%d %d %d", &t, &a, &b);
    // cerr << i << " : ";
    if (t == 1) {
      bs[a] = pre[b];
      // for (int j = 0; j < V; ++j)
        // cerr << bs[a][j];
      // cerr << endl;
    }
    else if (t == 2) {
      int c;
      scanf("%d", &c);
      bs[a] = bs[b] ^ bs[c];
      // for (int j = 0; j < V; ++j)
        // cerr << bs[a][j];
      // cerr << endl;
    }
    else if (t == 3) {
      int c;
      scanf("%d", &c);
      bs[a] = bs[b] & bs[c];
      // for (int j = 0; j < V; ++j)
        // cerr << bs[a][j];
      // cerr << endl;
    }
    else {
      bitset<V> res = bs[a] & mask[b];
      // cerr << res.count() << endl;
      printf("%d", ((int)res.count() & 1));
      // cerr << endl;
    }
  }
  printf("\n");
  return 0;
}