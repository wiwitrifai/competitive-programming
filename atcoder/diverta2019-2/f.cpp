#include <bits/stdc++.h>

using namespace std;

const int N = 101;
const long long DMAX = 1e11;

long long g[N][N], mul[N];
int p[N];

int main() {
  mul[0] = 1;
  for (int i = 1; i < 10; ++i) {
    mul[i] = mul[i-1] + 1;
    bool ok = 0;
    while (!ok) {
      ok = 1;
      set<int> st;
      for (int j = 0; j <= i && ok; ++j) {
        if (st.count(mul[j])) {
          ok = 0;
          break;
        }
        st.insert(mul[j]);
        for (int k = j+1; k <= i; ++k) {
          int now = mul[k] + mul[j];
          if (st.count(now)) {
            ok = 0;
            break;
          }
          st.insert(now);
        }
      }
      if (ok) break;
      ++mul[i];
    }
  }
  int N, n = 2;
  scanf("%d", &N);
  g[0][1] = g[1][0] = 1;
  long long last = 1;
  while (n < N) {
    ++n;
    long long cur = last;
    bool ok = 0;
    while (!ok) {
      ok = 1;
      for (int i = 0; i < n-1; ++i)
        g[i][n-1] = g[n-1][i] = mul[i] * cur;
      last = 0;
      for (int i = 0; i < n; ++i)
        p[i] = i;
      set<long long> st;
      do {
        if (p[0] > p[n-1]) continue;
        long long sum = 0;
        for (int i = 0; i + 1 < n; ++i)
          sum += g[p[i]][p[i+1]];
        if (st.count(sum)) {
          ok = 0;
          break;
        }
        st.insert(sum);
        last = max(last, sum);
        ++cur;
      } while (next_permutation(p, p+n));
    }
  }
  assert(last <= DMAX);
  cerr << last << endl;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%lld%c", g[i][j], j == N-1 ? '\n' : ' ');
    }
  }
  return 0;
}
