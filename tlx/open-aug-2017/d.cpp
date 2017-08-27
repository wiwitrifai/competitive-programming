#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, SQ = sqrt(N);

vector<int> child[N];

int up[N], gr[N], ng, n, cnt;
long long val[N];

long long get(int v) {
  // cerr << " get " << v << endl;
  long long ret = val[v];
  for (int u : child[v])
    ret += get(u);
  return ret;
}

int main() {
  int q;
  n = 1;
  long long ans = 0;
  scanf("%d", &q);
  cnt = 1;
  ng = 0;
  while (q--) {
    int t;
    long long u, v;
    scanf("%d %lld", &t, &u);
    if (t == 2) {
      printf("%lld\n", ans = get(u));
    }
    else {
      n++;
      scanf("%lld", &v);
      long long par = u ^ ans;
      assert(1 <= par && par <= n);
      if (cnt >= SQ) {
        gr[n] = ++ng;
        cnt = 0;
      }
      else
        gr[n]= ng;
      cnt++;
      if (gr[n] != gr[par])
        up[n] = par;
      else {
        child[par].push_back(n);
        up[n] = up[par];
      }
      int now = n;
      while (now >= 1) {
        val[now] += v;
        now = up[now];
      }
    }
  }


  return 0;
}
