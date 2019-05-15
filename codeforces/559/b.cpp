#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  string s = string((n-k)/2, '0') + "1";
  string ans = "";
  while (ans.size() < n)
    ans += s;
  ans.resize(n);
  cout << ans << endl;
  return 0;
}
