#include <bits/stdc++.h>

using namespace std;

set<long long > st;
int n, a[111];
long long k;

int main() {
  cin >> n >> k;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    sum += a[i];
    for (long long z = 1; z * z <= a[i]; z++) {
      long long y = (a[i]+z-1)/z;
      st.insert(z);
      st.insert(y);
    }
  }
  long long ans = 1, cur = 0, last = 1;
  for (auto it : st) {
    long long x = 0;
    for (int i = 0; i < n; i++) {
      x += (a[i] + it - 1) / it;
    }
    cur = x * it - sum;
    if (cur <= k) {
      ans = max(ans, it);
      long long z = (k - cur) / x;
      if (z >= 0)
        ans = max(ans, it+z);
    }
  }
  cout << ans << endl;
  return 0;
}