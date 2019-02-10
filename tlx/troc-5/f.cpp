#include <bits/stdc++.h>

using namespace std;

multiset<int> val, dif;

void del(int x) {
  auto it = val.find(x);
  assert(it != val.end());
  auto nx = it;
  auto pr = it;
  ++nx;
  if (nx != val.end()) {
    auto v = dif.find(*nx - x);
    dif.erase(v);
  }
  if (pr != val.begin()) {
    --pr;
    auto v = dif.find(x - *pr);
    dif.erase(v);
    if (nx != val.end()) {
      dif.insert(*nx - *pr);
    }
  }
  val.erase(it);
}

void add(int x) {
  val.insert(x);
  auto it = val.find(x);
  assert(it != val.end());
  auto nx = it;
  auto pr = it;
  ++nx;
  if (nx != val.end()) {
    dif.insert(*nx - x);
  }
  if (pr != val.begin()) {
    --pr;
    dif.insert(x - *pr);
    if (nx != val.end()) {
      auto v = dif.find(*nx - *pr);
      dif.erase(v);
    }
  }
}

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    b[i] = a[i];
  }
  sort(a, a+n);
  for (int i = 0; i < n; ++i) {
    val.insert(a[i]);
    if (i)
      dif.insert(a[i] - a[i-1]);
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 2) {
      long long ans = *val.rbegin() - *val.begin();
      ans -= *dif.begin();
      printf("%lld\n", ans);
    }
    else {
      int x, y;
      scanf("%d %d", &x, &y);
      --x;
      if (b[x] != y) {
        del(b[x]);
        add(b[x] = y);
      }
    }
  }
  return 0;
}