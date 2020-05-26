#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a, b, c;

template<typename Node>
vector<int> solve(function<bool(int, int)> cmp, int offs = 0, int addtime = 0) {
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), cmp);
  multiset<Node> st;
  int iid = 0;
  for (int i = 0; i < min(offs, (int)id.size()); ++i) {
    int v = id[iid + i];
    st.insert(Node(a[v], b[v], c[v], v));
  }
  priority_queue<int> que;
  int now = 0;
  vector<int> ans(n, -1);
  while (iid + offs < (int)id.size() || !st.empty()) {
    if ((int)que.size() == k) {
      now = max(-que.top(), now);
    }
    while (!que.empty() && -que.top() <= now) que.pop();
    assert ((int)que.size() < k);
    if (st.empty() && iid < (int)id.size()) {
      int v = id[iid];
      now = max(a[v], now);
    }
    while (iid + offs < (int)id.size() && a[id[iid]] <= now + addtime) {
      int v = id[iid + offs];
      st.insert(Node(a[v], b[v], c[v], v));
      ++iid;
    }
    if (!st.empty()) {
      auto it = st.begin();
      now = max(now, a[it->id]);
      ans[it->id] = now;
      que.push(-(now + it->b));
      st.erase(it);
    }
  }
  return ans;
}

struct Node {
  int a, b, c, id;
  Node(int a_, int b_, int c_, int id_) : a(a_), b(b_), c(c_), id(id_) {}
  bool operator<(const Node & rhs) const {
    long long x = 1LL * b * rhs.c, y = 1LL * rhs.b * c;
    return x < y;
  }
};

long long cost(const vector<int> & ans) {
  long long tot = 0;
  for (int i = 0; i < n; ++i) {
    tot += (ans[i] - a[i]) * 1LL * c[i];
  }
  return tot;
}


int main() {
  scanf("%d %d", &n, &k);
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[i]);
  auto cmp = [&](int l, int r) {
    return (a[l] == a[r]) ? 1LL * b[l] * c[r] < 1LL * b[r] * c[l] : a[l] < a[r];
  };
  auto cmp2 = [&](int l, int r) {
    return (a[l]+b[l] == a[r]+b[r]) ? 1LL * b[l] * c[r] < 1LL * b[r] * c[l] : a[l]+b[l] < a[r]+b[r];
  };
  vector<int> ans = solve<Node>(cmp, 0);
  long long best = cost(ans);
  auto update = [&](vector<int> res) {
    long long cur = cost(res);
    if (cur < best) {
      ans = res;
      best = cur;
    }
  };

  update(solve<Node>(cmp2, 0));

  for (int i = 1; i < 100; ++i) {
    update(solve<Node>(cmp2, i));
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 1; j < 13; ++j) {
      update(solve<Node>(cmp2, i, j));
    }
  }

  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], i+1 == n? '\n' : ' ');
  }
  return 0;
}
