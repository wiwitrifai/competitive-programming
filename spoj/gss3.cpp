#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5, inf = -1e9;
int sum[N << 2], suml[N << 2], sumr[N << 2], best[N << 2], n, a[N];
void build(int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    sum[id] = suml[id] = sumr[id] = a[l];
    best[id] = a[l];
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  suml[id] = max(suml[il], sum[il] + suml[ir]);
  sumr[id] = max(sumr[ir], sum[ir] + sumr[il]);
  best[id] = max(max(best[il], best[ir]), suml[ir] + sumr[il]);
}

pair<pair<int, int>, pair<int, int> > get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return {{-inf, -inf}, {-inf, -inf}};
  if (x <= l && r <= y) return {{best[id], sum[id]}, {suml[id], sumr[id]}};
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  auto res1 = get(x, y, il, l, mid);
  auto res2 = get(x, y, ir, mid, r);
  if (res1.first.first == -inf)
    return res2;
  if (res2.first.first == -inf)
    return res1;
  pair< pair<int, int>, pair<int, int> > ret;
  ret.first.first = max(max(res1.first.first, res2.first.first), res1.second.second + res2.second.first);
  ret.first.second = res1.first.second + res2.first.second;
  ret.second.first = max(res1.second.first, res1.first.second + res2.second.first);
  ret.second.second = max(res2.second.second, res2.first.second + res1.second.second);
  return ret;
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    sum[id] = suml[id] = sumr[id] = best[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  sum[id] = sum[il] + sum[ir];
  suml[id] = max(suml[il], sum[il] + suml[ir]);
  sumr[id] = max(sumr[ir], sum[ir] + sumr[il]);
  best[id] = max(max(best[il], best[ir]), suml[ir] + sumr[il]); 
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  build();
  int m;
  scanf("%d", &m);
  while (m--) {
    int ty, x, y;
    scanf("%d %d %d", &ty, &x, &y);
    if (ty)
      printf("%d\n", get(x-1, y).first.first);
    else
      update(x-1, y);
  }
  return 0;
}