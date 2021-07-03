#include <bits/stdc++.h>


using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> fwd(n, 1), bck(n, 1);
  int ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i+1] < a[i])
      fwd[i+1] = fwd[i] + 1;
  }
  for (int i = n-1; i > 0; --i) {
    if (a[i-1] > a[i])
      bck[i-1] = bck[i] + 1;
  }
  ans = max(ans, 1 + *max_element(fwd.begin(), fwd.end()));
  ans = max(ans, 1 + *max_element(bck.begin(), bck.end()));
  ans = min(ans, n);
  for (int i = 0; i + 2 < n; ++i) {
    if (a[i] - 1 > a[i+2]) {
      ans = max(ans, fwd[i] + 1 + bck[i+2]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
