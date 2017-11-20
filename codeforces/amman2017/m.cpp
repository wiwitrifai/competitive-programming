#include <bits/stdc++.h>

using namespace std;

const int N = 20;
multiset<int> mset;
int a[N], n;

int calc(int tot) {
  int cnt = 0;
  for (auto it = mset.begin(), it2 = --mset.end(); it != it2; it++) {
    while (it2 != it && (*it + *it2) > tot) it2--;
    if (it != it2 && *it + *it2 == tot) {
      cnt++;
      it2--;
    }
    if (it == it2) break;
  }
  return cnt;
}

bool add(int l, int r, int k) {
  bool ok = a[l-1] <= k && k <= a[r+1];
  for (int i = 0; i < l; i++) {
    auto it = mset.find(abs(k-a[i]));
    ok &= it != mset.end();
    if (!ok) {
      for (int j = 0; j < i; j++)
        mset.insert(abs(k-a[j]));
      return false;
    }
    mset.erase(it);
  }
  for (int i = r+1; i < n; i++) {
    auto it = mset.find(abs(k-a[i]));
    ok &= it != mset.end();
    if (!ok) {
      for (int j = 0; j < l; j++)
        mset.insert(abs(k-a[j]));
      for (int j = r+1; j < i; j++)
        mset.insert(abs(k-a[j]));
      return false;
    }
    mset.erase(it);
  }
  return ok;
}

void rem(int l, int r, int k) {
  for (int i = 0; i < l; i++)
    mset.insert(abs(k-a[i]));
  for (int i = r+1; i < n; i++)
    mset.insert(abs(k-a[i]));
}

bool solve(int l, int r) {
  if (r < l) return true;
  auto it = --mset.end();
  int dm = *it;
  if (add(l, r, dm)) {
    a[r] = dm;
    bool ok = 1;
    for (int i = 0; i < l; i++)
      if (calc(a[r]-a[i]) < r-l) {
        ok = 0;
        break;
      }
    if (ok && solve(l, r-1))
      return true;
    rem(l, r, a[r]);
  }
  if (add(l, r, a[n-1]-dm)) {
    a[l] = a[n-1]-dm;
    if (solve(l+1, r))
      return true;
    rem(l, r, a[l]);
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    mset.clear();
    int m = n * (n-1) /2;
    for (int i = 0; i < m; i++) {
      int d;
      scanf("%d", &d);
      mset.insert(d);
    }
    a[0] = 0;
    auto it = --mset.end();
    a[n-1] = *it;
    mset.erase(it);
    assert(solve(1, n-2));
    for (int i = 0; i < n; i++)
      printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}