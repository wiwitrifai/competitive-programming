#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> a, b, pa, pb;
int u, v;
long long ans;

void solve(int la, int ra, int lb, int rb) {
  //printf("%d %d %d %d\n", la, ra, lb, rb);
  if (la >= ra || lb >= rb) return;
  int mid = (la + ra) >> 1;
  auto x = pa[mid];
  long long cur = -1;
  int p = -1;
  for (int i = lb; i < rb; i++) {
    auto y = pb[i];
    if (y.first < x.first || y.second < x.second) continue;
    long long ncur = (y.first - x.first) * (y.second - x.second);
    if (ncur > cur) {
      cur = ncur;
      p = i;
    }
  }
  ans = max(ans, cur);
  if (p == -1) {
    p = lb;
    while (p < rb && pb[p].first < x.first) p++;
  }
  solve(la, mid, lb, min(p+1, rb));
  solve(mid+1, ra, p, rb);
}

int main() {
  ans = 0;
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a.emplace_back(v, u);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    b.emplace_back(v, u);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++) {
    if (!pa.empty() && pa.back().second <= a[i].second) continue;
    pa.push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    if (!pb.empty() && pb.back().second >= b[i].second) continue;
    pb.push_back(b[i]);
  }
  reverse(pb.begin(), pb.end());
  solve(0, pa.size(), 0, pb.size());
  cout << ans << endl;
  return 0;
}