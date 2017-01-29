#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n;
set< int > um;
void update(int x) {
  um.erase(x);
}
bool get(int x, int y) {
  auto it = um.lower_bound(x);
  return it == um.end() || *it >= y;
}
int q, t[N], x[N], y[N];
set< pair< int, int > > st[N << 2];
void insert(int it, int id = 1, int l = 0, int r = n) {
  st[id].insert(make_pair(y[it], it));
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x[it] < mid)
    insert(it, il, l, mid);
  else
    insert(it, ir, mid, r);
}
void erase(int it, int id = 1, int l = 0, int r = n) {
  st[id].erase(make_pair(y[it], it));
  if (r-l < 2) {
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x[it] < mid)
    erase(it, il, l, mid);
  else
    erase(it, ir, mid, r);
}
vector< int > fres;
void find(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    for (auto it : st[id]) {
      if (it.first > y)
        break;
      fres.push_back(it.second);
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  find(x, y, il, l, mid);
  find(x, y, ir, mid, r);
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++)
    um.insert(i);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", t+i, x+i);
    x[i]--;
    if (t[i]) {
      update(x[i]);
      fres.clear();
      auto it = um.lower_bound(x[i]);
      int r = it == um.end() ? n : *it, l = 0;
      if (it != um.begin())
        l = *(--it) + 1;
      find(l, r);
      cout << fres.size() << endl;
      for (int it : fres) {
        // cerr << "=" << it << endl;
        erase(it);
      }
    }
    else {
      scanf("%d", y+i), y[i];
      if (!get(x[i], y[i]))
        insert(i);
    }
  }
  return 0;
}