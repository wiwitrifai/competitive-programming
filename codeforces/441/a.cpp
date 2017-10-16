#include <bits/stdc++.h>

using namespace std;

int f(int n) {
  int ans = n;
  while (n > 0) {
    // cerr << ans << " " << n << endl;
    ans += n % 10;
    n /= 10;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  for (int i = max(1, n-100); i <= n; i++)
    if (f(i) == n)
      ans.push_back(i);
  printf("%d\n", ans.size());
  for (int x : ans)
    printf("%d\n", x);

  return 0;
}