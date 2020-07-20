#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long inf = (long long)2e18 + 1LL;

long long val[N];

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long mul(long long a, long long b) {
  if (a == 0)
    return a * b;
  if (b > inf / a)
    return inf;
  return min(inf, b * a);
}

vector<int> g[N];
int dep[N];

void dfs(int v, int par = -1) {
  for (int u : g[v]) {
    if (u == par) continue;
    dep[u] = dep[v] + 1;
    dfs(u, v);
  }
}


void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    g[i].clear();
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dep[0] = 0;
  dfs(0);
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", val[dep[i]], i+1 == n ? '\n' : ' ');
  }
}

int main() {
  for (int i = 0; i < N; ++i)
    val[i] = 1;
  for (int i = 100; i >= 1; --i) {
    int need = (i) / 2 + 1;
    int select = -1;
    long long smallest = inf;
    for (int j = 0; j < need; ++j) {
      long long biggest = 0;
      for (int k = j; k < 100; k += need) {
        long long res = mul(val[k], i / gcd(i, val[k]));
        biggest = max(biggest, res);
      }
      if (biggest < smallest) {
        select = j;
        smallest = biggest;
      }
    }
    if (select == -1 || smallest >= inf) {
      cerr << " fail " << endl;
      return 0;
    }
    for (int k = select; k < 100; k += need) {
      val[k] = mul(val[k], i / gcd(i, val[k]));
    }
  }
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
