#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k, p;
int a[N], b[N];

bool can(int x) {
  if (p == 2 && x == 1) {
    int cnt = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
      int now = (i & 1) ? 3 - a[i] : a[i];
      cnt += now == 2;
      cnt1 += now == 1;
    }
    return min(cnt, cnt1) <= k;
  }
  int cnt = 0, last = -1, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (last != a[i]) {
      cur += cnt / (x + 1);
      cnt = 0;
      last =a[i];
    }
    ++cnt;
  }
  cur += cnt / (x + 1);
  return cur <= k;
}

int main() {
  scanf("%d %d %d", &n, &k,&p);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  if (p == 1) {
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
      printf("%d%c", 1, i == n-1 ? '\n' : ' ');
    return 0;
  }
  int l = 1, hi = n;
  while (l < hi) {
    int mid = (l + hi) >> 1;
    if (can(mid))
      hi = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  if (p == 2) {
    if (l == 1) {
      int beda = 0;
      for (int i = 0; i < n; ++i) {
        b[i] = i & 1 ? 2 : 1;
        beda += a[i] != b[i];
      }
      if (beda > k) {
        beda = 0;
        for (int i = 0; i < n; ++i) {
          b[i] = i & 1 ? 1 : 2;
          beda += a[i] != b[i];
        }
      }
      for (int i = 0; i < n; ++i)
        printf("%d%c", b[i], i == n-1 ? '\n' : ' ');
    }
    else {
      for (int i = 0; i < n;) {
        int r = i;
        while (r < n && a[i] == a[r]) ++r;
        for (int z = i+l; z < r; z += 1+l) {
          a[z] = 3 - a[z];
        }
        if (((r-i) % (l + 1)) == 0) {
          swap(a[r-1], a[r-2]);
        }
        i = r;
      }
      for (int i = 0; i < n; ++i) {
        printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
      }
    }
  }
  else {
    int cnt = 0, last = -1;
    for (int i = 0; i < n; ++i) {
      if (last != a[i]) {
        last = a[i];
        cnt = 0;
      }
      ++cnt;
      if (cnt > l) {
        int beda = 1;
        while (beda == a[i] || beda == a[i+1]) ++beda;
        assert(beda <= p);
        a[i] = beda;
        cnt = 1;
        last = beda;
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
    }

  }
  return 0;
}