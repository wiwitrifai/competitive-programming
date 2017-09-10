#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segtree {
  segtree(vector<tuple<int, int, int>> a) : a(a) {
    int n = a.size();
    s.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    if (l > r) return;
    if (l == r) {
      int x, y, id;
      tie(x, y, id) = a[l];
      s[p].insert({y, id});
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    for (auto it : s[p + p]) s[p].insert(it);
    for (auto it : s[p + p + 1]) s[p].insert(it);
  }
  int find(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return -1;
    return find(1, 0, n - 1, x1, y1, x2, y2);
  }
  int find(int p, int l, int r, int x1, int y1, int x2, int y2) {
    if (x1 <= get<0>(a[l]) && get<0>(a[r]) <= x2) {
      auto it = s[p].lower_bound({y1, -1});
      if(it != s[p].end() && it->first <= y2) {
        return it->second;
      } else {
        return -1;
      }
    }
    int mid = (l + r) >> 1, ret;
    ret = find(p + p, l, mid, x1, y1, x2, y2);
    if (ret != -1) return ret;
    ret = find(p + p + 1, mid + 1, r, x1, y1, x2, y2);
    return ret;
  }
  void del(int x, int y, int id) {
    del(1, 0, n - 1, x, y, id);
  }
  void del(int p, int l, int r, int x, int y, int id) {
    s[p].erase({y, id});
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (id <= mid) {
      del(p + p, l, mid, x, y, id);
    } else {
      del(p + p + 1, mid + 1, r, x, y, id);
    }
  }

  // x, y, id sorted
  vector<set<pair<int, int>>> s;
  vector<tuple<int, int, int>> a;
  int n;
};

segtree* fence, flower, cow;
vector<pair<int, int>> x_fence, x_flower, x_cow;
int ans[N];

void dfs(int x1, int x2, int y1, int y2) {

}

int main() {
  int n_fence, n_flower, n_cow;
  scanf("%d", &n_fence);
  for (int i = 0; i < n; i++) {

  }

  return 0;
}