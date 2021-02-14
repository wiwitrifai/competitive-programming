#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int cnt = n * m;
  long long ans = 1;
  for (int i = 0; i < cnt-1; ++i) {
    ans = (ans * 2) % mod;
  }
  cout << ans << endl;
  return 0;
}
