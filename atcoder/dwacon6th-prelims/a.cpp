#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  bool ok = 0;
  vector<string> vs(n);
  vector<int> vt(n);
  for (int i = 0; i < n; ++i)
    cin >> vs[i] >> vt[i];
  string x;
  cin >> x;
  for (int i = 0; i < n; ++i) {
    if (ok)
      ans += vt[i];
    ok |= vs[i] == x;
  }
  printf("%lld\n", ans);
  return 0;
}
