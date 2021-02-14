#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
char s[N], t[N];
int sum[2];

void solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  scanf("%s %s", s, t);
  vector<int> l(q), r(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &l[i], &r[i]);
    --l[i];
  }
  set<pair<int, int>> st[2];
  int last = 0;
  for (int i = 0; i < n; ++i) {
    if (t[i] != t[last]) {
      st[t[last]-'0'].insert(make_pair(last, i));
      last = i;
    }
  }
  st[t[last]-'0'].insert(make_pair(last, n));
  for (int i = q-1; i >= 0; --i) {
    sum[0] = sum[1] = 0;
    for (int j = 0; j < 2; ++j) {
      vector<pair<int, int>> padd, pdel;
      auto it = st[j].lower_bound(make_pair(l[i], -1));
      while (it != st[j].begin()) {
        auto pre = it;
        --pre;
        if (pre->second <= l[i]) break;
        it = pre;
      }
      while (it != st[j].end() && it->first < r[i]) {
        sum[j] += min(r[i], it->second) - max(it->first, l[i]);
        if (it->second > r[i]) {
          padd.emplace_back(r[i], it->second);
        }
        if (it->first < l[i]) {
          padd.emplace_back(it->first, l[i]);
        }
        pdel.emplace_back(*it);
        ++it;
      }
      for (auto & p : pdel)
        st[j].erase(p);
      for (auto & p : padd) {
        if (p.first >= p.second) continue;
        st[j].insert(p);
      }
    }
    assert(sum[0] + sum[1] == r[i] - l[i]);
    if (sum[0] == sum[1]) {
      puts("NO");
      return;
    }
    int biggest = sum[0] < sum[1] ? 1 : 0;
    st[biggest].insert(make_pair(l[i], r[i]));
  }
  for (int i = 0; i < 2; ++i) {
    char now = '0' + i;
    for (auto & e : st[i]) {
      for (int j = e.first; j < e.second; ++j) {
        if (s[j] != now) {
          puts("NO");
          return;
        }
      }
    }
  }
  puts("YES");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
