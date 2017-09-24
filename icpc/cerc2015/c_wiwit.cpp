#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int val[N << 2], reset[N << 2];

void build(int id = 1, int l = 0, int r = N) {
  val[id] = reset[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void push(int id) {
  if (reset[id] == 0 && val[id] == 0) return;
  int il = id << 1, ir = il | 1; 
  if (reset[id]) {
    val[il] = val[ir] = 0;
    reset[il] = reset[ir] = 1;
    reset[id] = 0;
  }
  val[il] += val[id];
  val[ir] += val[id];
  val[id] = 0;
}

int get(int x, int id = 1, int l = 0, int r = N) {
  if (r-l < 2)
    return val[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  if (x < mid)
    return get(x, il, l, mid);
  else
    return get(x, ir, mid, r);
}

void upd(int x, int y, int add, bool res, int id = 1, int l = 0, int r = N) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    if (res) {
      reset[id] = 1;
      val[id] = 0;
    }
    val[id] += add;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  push(id);
  upd(x, y, add, res, il, l, mid);
  upd(x, y, add, res, ir, mid, r);
}
vector<pair<int, int>> addp[N], cow[N], remp[N];
vector<int> flower[N];
int save[N];
int ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    d++;
    a--;
    addp[c].emplace_back(b, d);
    remp[a].emplace_back(b, d);
  }
  scanf("%d", &n);
  memset(save, 0, sizeof save);
  for (int i = 0; i < n; i++) {
    int r, c;
    scanf("%d %d", &r, &c);
    flower[r].push_back(c);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int r, c;
    scanf("%d %d", &r, &c);
    cow[r].emplace_back(i, c);
  }
  build();
  set<int> batas;
  for (int i = N-1; i >= 0; i--) {
    for (auto it : addp[i]) {
      upd(it.first, it.second, 0, 1);
      batas.insert(it.first);
      batas.insert(it.second);
    }
    sort(remp[i].begin(), remp[i].end());
    for (auto it : remp[i]) {
      int cur = get(it.second);
      upd(it.first, it.second, cur, 1);
      int le = 0;
      auto bef = batas.lower_bound(it.first);
      if (bef != batas.begin()) {
        bef--;
        le = *bef;
      }
      upd(le, it.first, save[it.second], 0);
      save[le] += save[it.second];
      save[it.first] = save[it.second] = 0;
      batas.erase(it.first);
      batas.erase(it.second);
    }
    for (int c : flower[i]) {
      int le = 0;
      auto it = batas.upper_bound(c);
      if (it != batas.begin()) {
        it--;
        le = *it;
      }
      save[le]++;
      upd(le, c+1, +1, 0);
    }
    for (auto it : cow[i]) {
      ans[it.first] = get(it.second);
    }
  }
  for (int i = 0; i < n; i++)
    printf("%d\n", ans[i]);
  return 0;
}