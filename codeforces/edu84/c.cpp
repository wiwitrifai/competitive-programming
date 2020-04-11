#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  string ans = string(n-1, 'U') + string(m-1, 'L');
  for (int i = 0; i < n; ++i) {
    if (i & 1)
      ans += string(m-1, 'L');
    else
      ans += string(m-1, 'R');
    if (i + 1 < n)
      ans += string(1, 'D');
  }
  cout << ans.size() << endl;
  cout << ans << endl;
  return 0;
}
