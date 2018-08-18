#include <bits/stdc++.h>

using namespace std;

const int N = 3030;
vector<long long> vote[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int p, b;
    scanf("%d %d", &p, &b); --p;
    vote[p].push_back(b);
    if (p)
      ans += b;
  }
  for (int i = 0; i < m; ++i) {
    sort(vote[i].begin(), vote[i].end());
  }
  for (int need = 1; need <= n; ++need) {
    vector<int> sisa;
    int cnt = vote[0].size();
    long long cost = 0;
    for (int j = 1; j < m; ++j) {
      int cur = vote[j].size();
      cur = min(cur, need-1);
      int hapus = (int)vote[j].size() - cur;
      for (int k = 0; k < hapus; ++k)
        cost += vote[j][k], ++cnt;
      for (int k = hapus; k < vote[j].size(); ++k)
        sisa.push_back(vote[j][k]);
    }
    if (cnt < need) {
      sort(sisa.begin(), sisa.end());
      int butuh = need - cnt;
      butuh = min(butuh, (int)sisa.size());
      for (int j = 0; j < butuh; ++j)
        cost += sisa[j];
    }
    ans = min(ans, cost);
  }
  printf("%lld\n", ans);
  return 0;
}