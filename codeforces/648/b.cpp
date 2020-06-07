#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    int cnt[2];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
      scanf("%d", b+i);
      cnt[b[i]]++;
    }
    bool ok = true;
    for (int i = 0; i + 1 < n; ++i)
      ok &= a[i] <= a[i+1];
    puts((ok || (cnt[0] > 0 && cnt[1] > 0)) ? "Yes" : "No");
  }

  return 0;
}
