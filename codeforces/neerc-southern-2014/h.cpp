#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int c[N];

bool cmp(tuple<int, int, int> le, tuple<int, int, int> ri) {
  int p, q, r, x, y, z;
  tie(p, q, r) = le;
  tie(x, y, z) = ri;
  return make_tuple(c[p], c[q], c[r]) < make_tuple(c[x], c[y], c[z]);
}

int main() {
  int n;
  scanf("%d", &n);
  int mi = n;
  vector< pair<int, int> > pos;
  for (int i = 0; i < n; ++i) {
    scanf("%d", c+i);
    pos.emplace_back(c[i], i);
  }
  sort(pos.begin(), pos.end());
  set<pair<int, int> > st;
  int l = pos[0].second, r = pos[1].second;
  if (l > r) {
    swap(l, r);
  }
  st.insert(make_pair(l, r));
  st.insert(make_pair(r, l+n));
  int off = l;
  for (int i = 2; i < n; ++i) {
    if (pos[i].second < l) pos[i].second += n;
  }
  sort(pos.begin()+2, pos.end());
  vector<tuple<int, int, int> > ans;
  for (int i = 2; i < n;) {
    int val = pos[i].first, cur = pos[i].second;
    if (cur < off) cur += n;
    auto it = st.upper_bound(make_pair(cur, cur));
    assert(it != st.begin());
    --it;
    l = it->first, r = it->second;
    st.erase(it);
    vector<int> inrange;
    while (i < n && pos[i].first == val && pos[i].second < r) {
      inrange.push_back(pos[i].second); ++i;
    }
    if (c[r % n] > c[l % n]) swap(l, r), reverse(inrange.begin(), inrange.end());
    for (int x : inrange) {
      vector<pair<int, int> > val = {{c[l % n], l % n}, {c[x % n], x % n}, {c[r % n], r % n}};
      sort(val.begin(), val.end());
      ans.emplace_back(val[0].second, val[1].second, val[2].second);
      if (l < x)
        st.insert(make_pair(l, x));
      else
        st.insert(make_pair(x, l));
      l = x;
    }
    if (l < r)
      st.insert(make_pair(l, r));
    else
      st.insert(make_pair(r, l));
  }
  sort(ans.begin(), ans.end(), cmp);
  for (auto it : ans) {
    int u, v, w;
    tie(u, v, w) = it;
    printf("%d %d %d\n", u+1, v+1, w+1);
  }
  return 0;
}