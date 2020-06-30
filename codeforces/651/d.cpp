#include <bits/stdc++.h>

using namespace std;

vector<int> a;

int calc(int limit) {
  int ret = 0;
  bool odd = false;
  for (int x : a) {
    if (odd) {
      if (x > limit) continue;
      ++ret;
      odd = !odd;
    } else {
      ++ret;
      odd = !odd;
    }
  }
  int cnt = 0;
  odd = true;
  for (int x : a) {
    if (odd) {
      if (x > limit) continue;
      ++cnt;
      odd = !odd;
    } else {
      ++cnt;
      odd = !odd;
    }
  }
  return max(ret, cnt);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> val = a;
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  int lo = 0, hi = val.size()-1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (calc(val[mid]) >= k)
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d\n", val[lo]);
  return 0;
}
