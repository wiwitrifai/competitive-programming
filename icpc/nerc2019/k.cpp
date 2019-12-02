#include <bits/stdc++.h>

using namespace std;

const int N = 77;

long long C[N][N];

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = (C[i-1][j-1] + C[i-1][j]);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    long long k;
    scanf("%lld", &k);
    long long dp0 = 0, dp1 = 0;
    vector<int> d;
    for (int i = 2; k; ++i) {
      d.push_back(k % i);
      k /= i;
    }
    sort(d.begin(), d.end());
    vector<pair<int, int>> vcnt;
    int last = 0, cnt = 0;
    for (int i = 0; i < (int)d.size(); ++i) {
      if (d[i] != last) {
        vcnt.emplace_back(cnt, last);
        cnt = 0;
        last = d[i];
      }
      ++cnt;
    }
    vcnt.emplace_back(cnt, last);
    int s = vcnt[0].first;
    dp0 = 1;
    for (int i = 1; i < (int)vcnt.size(); ++i) {
      int c = vcnt[i].first, x = vcnt[i].second;
      int l = x-1, r = s, len = r - l + 1;
      long long c0 = 0, c1 = C[c - 1 + len - 1][len - 1];
      if (len > 1) {
        --len;
        c0 = C[c + len - 1][len - 1];
      }
      long long res0 = dp0 * c0;
      long long res1 = dp1 * (c0 + c1) + dp0 * c1;
      dp0 = res0;
      dp1 = res1;
      s += c;
    }
    printf("%lld\n", dp1-1);
  }
  return 0;
}
