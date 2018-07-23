/**
 *    author:  tourist
 *    created: 16.03.2018 20:33:14       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
 
  void init(int _n) {
    n = _n;
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
 
struct node {
  int a = 0;
 
  inline void operator += (node &other) {
    a ^= other.a;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 20005;
  vector< vector<string> > a(MAX);
  int cnt;
  cin >> cnt;
  while (cnt--) {
    int id;
    string str;
    cin >> id >> str;
    a[id].push_back(str);
  }
  vector<int> grundy(MAX), sizes(MAX);
  for (int id = 0; id < MAX; id++) {
    sizes[id] = (int) a[id].size();
    grundy[id] = 0;
    if (a[id].empty()) {
      continue;
    }
    sort(a[id].begin(), a[id].end());
    a[id].resize(unique(a[id].begin(), a[id].end()) - a[id].begin());
    int sz = (int) a[id].size();
    vector< vector<int> > g(sz);
    vector<int> stc, roots;
    for (int i = 0; i < sz; i++) {
      string &s = a[id][i];
      while (!stc.empty() && s.substr(0, a[id][stc.back()].length()) != a[id][stc.back()]) {
        stc.pop_back();
      }
      if (!stc.empty()) {
        g[stc.back()].push_back(i);
      } else {
        roots.push_back(i);
      }
      stc.push_back(i);
    }
    vector<int> aux(sz);
    for (int i = sz - 1; i >= 0; i--) {
      aux[i] = 0;
      for (int j : g[i]) {
        aux[i] ^= aux[j];
      }
      aux[i]++;
    }
    for (int i : roots) {
      grundy[id] ^= aux[i];
    }
  }
  int n;
  cin >> n;
  vector<int> l(n), r(n), k(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i] >> k[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return k[i] < k[j];
  });
  vector<int> order_ids(MAX);
  iota(order_ids.begin(), order_ids.end(), 0);
  sort(order_ids.begin(), order_ids.end(), [&](int i, int j) {
    return sizes[i] < sizes[j];
  });
  int max_grundy = *max_element(grundy.begin(), grundy.end());
  vector< vector<int> > by_grundy(max_grundy + 1);
  vector<int> pos(MAX);
  for (int i = 0; i < MAX; i++) {
    if (sizes[i] > 0) {
      pos[i] = (int) by_grundy[grundy[i]].size();
      by_grundy[grundy[i]].push_back(i);
    }
  }
  vector< fenwick<int> > fenw(max_grundy + 1);
  for (int i = 0; i <= max_grundy; i++) {
    fenw[i].init(by_grundy[i].size());
  }
  fenwick<node> fenw2;
  fenw2.init(MAX + 1);
  vector<int> res(n);
  int ptr = 0;
  for (int i : order) {
    while (ptr < MAX && sizes[order_ids[ptr]] <= k[i]) {
      if (sizes[order_ids[ptr]] > 0) {
        fenw[grundy[order_ids[ptr]]].modify(pos[order_ids[ptr]], 1);
        fenw2.modify(order_ids[ptr], {grundy[order_ids[ptr]]});
      }
      ptr++;
    }
    int total = fenw2.get(r[i]).a ^ fenw2.get(l[i] - 1).a;
    if (total <= max_grundy) {
      int from = lower_bound(by_grundy[total].begin(), by_grundy[total].end(), l[i]) - by_grundy[total].begin();
      int to = lower_bound(by_grundy[total].begin(), by_grundy[total].end(), r[i] + 1) - by_grundy[total].begin();
      to--;
      if (from <= to) {
        res[i] = fenw[total].get(to) - fenw[total].get(from - 1);
      }
    }
  }
  for (int x : res) {
    cout << x << '\n';
  }
  return 0;
}