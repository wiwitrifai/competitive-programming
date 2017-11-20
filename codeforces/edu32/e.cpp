#include <bits/stdc++.h>

using namespace std;

const int N = 40;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int mid = n / 2;
  vector<int> vl, vr;
  int nleft = 1 << mid, nright = 1 << (n - mid);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i] %= m;
  }
  for (int mask = 0; mask < nleft; mask++) {
    int now = 0;
    for (int i = 0; i < mid; i++) if (mask & (1 << i)) {
      now += a[i];
      if (now >= m) now -= m;
    }
    vl.push_back(now);
  }
  for (int mask = 0; mask < nright; mask++) {
    int now = 0;
    for (int i = mid; i < n; i++) if (mask & (1 << (i- mid))) {
      now += a[i];
      if (now >= m) now -= m;
    }
    vr.push_back(now);
  }
  sort(vl.begin(), vl.end());
  sort(vr.begin(), vr.end());
  int ans = (vl.back() + vr.back()) % m;
  for (int i = 0, j = (int)vr.size()-1; i < vl.size(); i++) {
    while (j >= 0 && vl[i] + vr[j] >= m) j--;
    if (j >= 0)
      ans = max(ans, vl[i] + vr[j]);
  }
  printf("%d\n", ans);
  return 0;
}