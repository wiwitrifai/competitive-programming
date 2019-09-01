#include <bits/stdc++.h>

using namespace std;

struct SegTree {
public:
  SegTree(int n) : n(n), sum(n << 2, 0), add(n << 2, 0) {};
  void Update(int x, int y, long long a) {
    Update_(x, y, a, 1, 0, n);
  }
  long long Get(int x, int y) {
    return Get_(x, y, 1, 0, n);
  }

private:
  int n;
  vector<long long> sum, add;
  void UpdateSingle(int id, int l, int r, long long a) {
    if (a == 0)
      return;
    sum[id] += 1LL * a * (r-l);
    add[id] += a;
  }
  void PushDown(int id, int l, int r) {
    if (add[id] == 0) return;
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    UpdateSingle(il, l, mid, add[id]);
    UpdateSingle(ir, mid, r, add[id]);
    add[id] = 0;
  }
  void Update_(int x, int y, long long a, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      UpdateSingle(id, l, r, a);
      return;
    }
    PushDown(id, l, r);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    Update_(x, y, a, il, l, mid);
    Update_(x, y, a, ir, mid, r);
    sum[id] = sum[il] + sum[ir];
  }
  long long Get_(int x, int y, int id, int l, int r) {
    if (x >= r || l >= y) return 0;
    if (x <= l && r <= y) return sum[id];
    PushDown(id, l, r);
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    return Get_(x, y, il, l, mid) + Get_(x, y, ir, mid, r);
  }
};

const int N = 2e5 + 5;

vector<pair<int, int>> queries[N];
long long ans[N];

template<typename T, typename K>
ostream& operator<<(ostream& os, pair<T, K> v) {
  return os << "(" << v.first << "," << v.second << ")";
}

template<typename T>
ostream& operator<<(ostream& os, vector<T> & v) {
  os << "[";
  for (T x : v)
    os << x << ",";
  return os << "]";
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    queries[l].emplace_back(i, r);
  }
  vector<pair<int, int>> ranges;
  SegTree segs(n);
  for (int i = n-1; i >= 0; --i) {
    int now = a[i], last = i;
    vector<pair<int, int>> new_ranges;
    for (auto it : ranges) {
      it.first = __gcd(it.first, now);
      if (it.first != now) {
        new_ranges.emplace_back(now, last);
        segs.Update(last, it.second, now);
        now = it.first;
        last = it.second;
      }
    }
    ranges.swap(new_ranges);
    ranges.emplace_back(now, last);
    segs.Update(last, n, now);
    for (auto it : queries[i]) {
      ans[it.first] = segs.Get(i, it.second);
    }
  }
  for (int i = 0; i < m; ++i)
    printf("%lld\n", ans[i]);
  return 0;
}
