#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<int> pw;


int main() {
  string s;
  cin >> s;
  int n = s.size();
  pw.push_back(1);
  for (int i = 0; i < 2 * n; ++i) {
    pw.push_back(pw.back() * 2LL % mod);
  }
  long long sum[2];
  sum[0] = sum[1] = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int c = s[i] -'0', other = c^1;
    ans = (ans + sum[other] * pw[n-1-i]) % mod;
    sum[c] = (sum[c] + pw[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
