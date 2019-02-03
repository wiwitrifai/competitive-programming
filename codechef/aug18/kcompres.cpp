#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int ma[N << 2], n;

void build(int id = 1, int l = 0, int r = n) {
  ma[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return 0;
  if (x <= l && r <= y) return ma[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

void update(int x, int v, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    assert(x == l);
    ma[id] = v;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, v, il, l, mid);
  else
    update(x, v, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

int a[N], b[N], c[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long s;
    scanf("%d %lld", &n, &s);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      b[i] = i;
    }
    sort(b, b+n, [&](int l, int r) {
      return a[l] == a[r] ? l < r : a[l] < a[r];
    });
    int l = 0, r = n+1;
    while (l < r) {
      int mid = (l + r) >> 1;
      build();
      for (int i = 0, j = 0; i < n; i = j) {
        j = i;
        int now = a[b[j]];
        while (j < n && a[b[j]] == now) ++j;
        for (int k = i; k < j; ++k) {
          c[k] = get(max(0, b[k]-mid), min(n-1, b[k]+mid) + 1) + 1;
        }
        for (int k = i; k+1 < j; ++k) {
          if (b[k+1] - b[k] <= mid)
            c[k+1] = max(c[k], c[k+1]);
        }
        for (int k = j-1; k > i; --k) {
          if (b[k] - b[k-1] <= mid)
            c[k-1] = max(c[k], c[k-1]);
        }
        for (int k = i; k < j; ++k)
          update(b[k], c[k]);
      }
      long long sum = 0;
      for (int i = 0; i < n; ++i)
        sum += c[i];
      if (sum <= s)
        l = mid + 1;
      else
        r = mid;
    }
    printf("%d\n", l);
  }
  return 0;
}