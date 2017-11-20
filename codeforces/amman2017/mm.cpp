#include <bits/stdc++.h>

using namespace std;

const int N = 40020;
set<int> mset;
int a[N], n;
int cnt[N];

void upd(int d, int val) {
  if (cnt[d] == 0 && cnt[d] + val > 0)
    st.insert(d);
  if (cnt[d] > 0 && cnt[d] + val == 0)
    st.erase(d);
  cnt[d] += val;
}
bool add(int l, int r, int k) {
  bool ok = 1;
  for (int i = 0; i < l; i++) {
    auto it = mset.find(abs(k-a[i]));
    ok &= a[i] <= k && it != mset.end();
    if (!ok) {
      for (int j = 0; j < i; j++)
        mset.insert(abs(k-a[j]));
      return false;
    }
    mset.erase(it);
  }
  for (int i = r+1; i < n; i++) {
    auto it = mset.find(abs(k-a[i]));
    ok &= a[i] >= k && it != mset.end();
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
    if (solve(l, r-1))
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
      cnt[d]++;
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