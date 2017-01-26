#include <bits/stdc++.h>

using namespace std;

struct bit {
  int n;
  vector< int > a;
  bit(int n) : n(n) {
    a.assign(n+1, 0);
  }
  void upd(int x, int v) {
    x++;
    for (; x <= n; x += x&(-x))
      a[x] += v;
  }
  int get(int x) {
    x++;
    if (x < 0)
      return 0;
    int ret = 0;
    for (; x; x -= x&(-x))
      ret += a[x];
    return ret;
  }
};
const int N = 1e5 + 5, F = 1e4 + 20;
bit * b[F];
vector< int > xx[F];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector< pair< int, pair<int, int > > > vs;
  for (int i = 0; i < n; i++) {
    int r, x, f;
    scanf("%d %d %d", &x, &r, &f);
    vs.push_back({-r, {x, f}});
    xx[f].push_back(x);    
  }
  for (int i = 0; i < F; i++) {
    sort(xx[i].begin(), xx[i].end());
    b[i] = new bit(xx[i].size());
  }
  sort(vs.begin(), vs.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x = vs[i].second.first, r = -vs[i].first, f = vs[i].second.second;
    for (int j = max(0, f-k); j <= f+k; j++) {
      int idr = upper_bound(xx[j].begin(), xx[j].end(), x+r) - xx[j].begin() - 1;
      int idl = lower_bound(xx[j].begin(), xx[j].end(), x-r) - xx[j].begin() - 1;
      ans += b[j]->get(idr) - b[j]->get(idl);
    }
    int id = lower_bound(xx[f].begin(), xx[f].end(), x) - xx[f].begin();
    b[f]->upd(id, +1);
  }
  cout << ans << endl;
  return 0;
}