#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int ma = a[i];
    long long now = 0;
    for (int j = i-1; j >= 0; j--) {
      ma = max(ma, a[j]);
      if((a[i] & a[j]) == a[i] || (a[i] & a[j]) == a[j]) {
        // cerr << a[j] << " " << ma << endl;
        now += ma;
      }
    }
    // cerr << i << " brute " << now << endl;
    ans += now;
  }
  printf("%lld\n", ans);

  return 0;
}