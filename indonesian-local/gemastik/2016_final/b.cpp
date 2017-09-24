#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

vector<int> v;
vector<pair<int, int > > res;
void rec(int id, int s, int d) {
  if (id == 0) {
    res.emplace_back(d, s);
    return;
  }
  id--;
  rec(id, s, d);
  rec(id, s, d-v[id]);
  rec(id, s+v[id], d+v[id]);
}

vector<pair<int, int> > process(vector<int>& p) {
  res.clear();
  v = p;
  rec(p.size(), 0, 0);
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> le, ri;
    int tot = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      tot += x;
      if (i < n/2)
        le.push_back(x);
      else
        ri.push_back(x);
    }
    int s4 = tot/4;
    vector<pair<int, int> > a = process(le), b = process(ri);
    for (pair<int, int> & p : a)
      p.first *= -1, p.second *= -1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0, j = 0; i < a.size(); i++) {
      while (j < b.size() && (b[j].first < a[i].first || (b[j].first == a[i].first && b[j].second - a[i].second <= s4))) j++;
      if (j < b.size() && b[j].first == a[i].first) {
        int x = b[j].second - a[i].second;
        ans = max(ans, 1LL * (tot - 2 * x) * x);
      }
      if (j >= 0 && b[j-1].first == a[i].first) {
        int x = b[j-1].second - a[i].second;
        ans = max(ans, 1LL * (tot - 2 * x) * x);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}