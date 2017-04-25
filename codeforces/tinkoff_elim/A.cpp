#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int r = 0, mi;
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    if (i == 0)
      r = a[i] % k, mi = a[i];
    else {
      mi = min(mi, a[i]);
      if ((a[i] % k) != r)
        ok = 0;
    }
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (a[i]-mi)/k;
  }
  cout << ans << endl;
  return 0;
}