#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];

pair<int, int> ans[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 1; i < n; ++i) {
    ans[i] = {a[0], a[i]};
    if (a[0] < a[i])
      swap(a[0], a[i]);
  }
  for (int i = 0; i < q; ++i) {
    long long m;
    scanf("%lld", &m);
    if (m < n) {
      printf("%d %d\n", ans[m].first, ans[m].second);
    }
    else {
      m %= (n-1);
      if (m == 0)
        m = n-1;
      printf("%d %d\n", a[0], a[m]);
    }
  }
  return 0;
}
