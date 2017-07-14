#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

pair<int, int> a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i].first), a[i].second = i;
  sort(a, a+n);
  int last = -1, cur = a[0].first, bef = -1, af = -1, cb = 0, ca = 0, all = n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].first != cur) {
      int now = -1;
      if (cb) {
        ans += all;
        now = bef;
        all -= ca;
        ca = cb;
        cb = 0;
      }
      else
        now = af;
      last = now;
      bef = af = -1;
    }
    if (a[i].second < last)
      bef = max(bef, a[i].second), cb++;
    else
      ca++;
    af = max(af, a[i].second);
    cur = a[i].first;
  }
  if (cb) {
    ans += all;
    all -= ca;
  }
  ans += all;
  cout << ans << endl;
  return 0;
}