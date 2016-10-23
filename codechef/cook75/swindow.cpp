#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e8;

int n, k, q, a[N], all;
vector< pair<int, int > > le[N << 2], ri[N << 2];
int len[N << 2];

void combine(int id, int l, int r) {
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  le[id].clear();
  ri[id].clear();
  int last = 0;
  for (int i = 0; i < le[il].size(); i++) {
    le[id].push_back(le[il][i]);
    last |= le[il][i].first;
  }
  for (int i = 0; i < le[ir].size(); i++) {
    if ((last | le[ir][i].first) != last) {
      last |= le[ir][i].first;
      le[id].push_back({last, le[ir][i].second});
    }
  }
  last = 0;
  for (int i = 0; i < ri[ir].size(); i++) {
    ri[id].push_back(ri[ir][i]);
    last |= ri[ir][i].first;
  }
  for (int i = 0; i < ri[il].size(); i++) {
    if ((last | ri[il][i].first) != last) {
      last |= ri[il][i].first;
      ri[id].push_back({last, ri[il][i].second});
    }
  }
  int j = (int)le[ir].size()-1;
  len[id] = min(len[il], len[ir]);
  for (int i = 0; i < ri[il].size(); i++) {
    while (j > 0) {
      if ((le[ir][j-1].first | ri[il][i].first) == all)
        j--;
      else
        break;
    }
    if (j >= 0 && j < le[ir].size() && (le[ir][j].first | ri[il][i].first) == all) {
      len[id] = min(len[id], le[ir][j].second - ri[il][i].second + 1);
    }
  }
}
void build(int id = 1, int l = 0, int r = n) {
  le[id].clear();
  ri[id].clear();
  if (r-l < 2) {
    le[id].push_back({1<<a[l], l});
    ri[id].push_back({1<<a[l], l});
    if (k == 1)
      len[id] = 1;
    else
      len[id] = inf;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  combine(id, l, r);
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    le[id][0].first = 1<<v;
    ri[id][0].first = 1<<v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  combine(id, l, r);  
}


int main() {
  scanf("%d %d %d", &n, &k, &q);
  all = (1<<k) - 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i]--;
  }
  build();
  while (q--) {
    int x, v;
    scanf("%d %d", &x, &v);
    update(x-1, v-1);
    printf("%d\n", len[1] == inf ? -1 : len[1]);
  }
  return 0;
}