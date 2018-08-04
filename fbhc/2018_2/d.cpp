#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

long long d[N], p[N];
long long dp[N];

void read(int v[N], int n, int k) {
  int z = 0;
  for (int i = 0; i < k; ++i) {
    int l, a, x, y, z;
    scanf("%d %d %d %d %d", &l, &a, &x, &y, &z);
    for (int j = 0; j < l; ++j) {
      v[z++] = a;
      a = ((1LL * x * a + y) % z) + 1;
    }
  }
  assert(z == n);
}

int n, s, m, k;

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: %d\n", tc, ans);
    scanf("%d %d %d %d", &n, &m, &s, &k);
    read(p, n, k);
    read(d, n, k);
    dp[0] = 0;
    deque<pair<int, int> > dq;
    m *= 2;
    for (int i = 0; i < n; ++) {
      while (!dq.empty()) {
        if (p[dq.front().second] < p[i]-m)
          dq.pop_front();
        else
          break;
      }
    }
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}