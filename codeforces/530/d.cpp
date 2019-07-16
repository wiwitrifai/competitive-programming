#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

vector<pair<long long, long long> > vp[N << 2];
int cnt[N << 2];
long long sum[N << 2];
vector<int> add[N << 2];
int n;

void push(int x, int y, int z, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    add[id].push_back(z);
    ++cnt[id];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(x, y, z, il, l, mid);
  push(x, y, z, ir, mid, r);
}

void traverse(int id = 1, int l = 0, int r = n) {
  for (int x : add[id]) {
    if (sum[id] * 2 < x) {
      vp[id].emplace_back(sum[id], x);
      sum[id] += x;
      continue;
    }
    sum[id] += x;
    vector<pair<long long, long long> > res;
    for (auto & it : vp[id]) {
      if (it.second <= x) {
        res.push_back(it);
        continue;
      }
      if (it.first >= x) {
        it.first += x;
        if (it.first * 2 < it.second)
          res.push_back(it);
        continue;
      }
      if (it.first * 2 < x)
        res.emplace_back(it.first, x);
      it.first += x;
      if (it.first * 2 < it.second)
        res.push_back(it);
    }
    vp[id].swap(res);
  }
  if (r-l < 2) {
    printf("%d\n", max(cnt[id] - (int)vp[id].size(), 0));
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  cnt[il] += cnt[id];
  vp[il] = vp[id];
  sum[il] = sum[id];
  traverse(il, l, mid);

  sum[ir] = sum[id];
  cnt[ir] += cnt[id];
  vp[ir] = vp[id];
  traverse(ir, mid, r);
}

int main() {
  int q;
  scanf("%d", &q);
  n = q;
  set<pair<int, int> > st;
  for (int i = 0; i < q; ++i) {
    char c[3];
    int x;
    scanf("%s %d", c, &x);
    if (c[0] == '-') {
      auto it = st.lower_bound(make_pair(x, -1));
      assert(it != st.end() && it->first == x);
      push(it->second, i, x);
      st.erase(it);
    }
    else
      st.insert(make_pair(x, i));
  }
  for (auto it : st) {
    push(it.second, q, it.first);
  }
  traverse();
  return 0;
}