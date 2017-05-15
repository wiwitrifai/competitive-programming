#include <bits/stdc++.h>

using namespace std;

vector< int > pre(const vector< pair<int, int> >&  x) {
  int n = x.size();
  int all = 0;
  for (auto c : x) {
    all += c.second;
  }
  vector< int > v;
  v.assign(all + 2, -1);
  v[0] = 0;
  all = 0;
  for (auto it : x) {
    for (int j = 0; j <= all; j++) if (v[j] != -1 && v[j+it.second] < v[j] + it.first) {
      v[j+it.second] = v[j] + it.first;
    }
    all += it.second;
  }
  for (int i = 0; i+1 < v.size(); i++)
    v[i+1] = max(v[i], v[i+1]);
  return v;
}

int main() {
  int n;
  scanf("%d", &n);
  vector< pair< int, int > > w, d, l;
  for (int i = 0; i < n; i++) {
    char t[5];
    int a, b;
    scanf("%s %d %d", t, &a, &b);
    a += b;
    swap(a, b);
    if (t[0] == 'W')
      w.emplace_back(a, b);
    else if (t[0] == 'D')
      d.emplace_back(a, b);
    else
      l.emplace_back(a, b);
  }
  vector< int > p = pre(w), q = pre(d), r = pre(l);
  int up = 0, uq = 0, ur = 0;
  int ans = 0;
  for (int i = 0; i < max(p.size(), max(q.size(), r.size())); i++) {
    if (i < p.size()) up = max(up, p[i]);
    if (i < q.size()) uq = max(uq, q[i]);
    if (i < r.size()) ur = max(ur, r[i]);
    ans = max(ans, up + uq + ur - i);
  }
  printf("%d\n", ans);
  return 0;
}