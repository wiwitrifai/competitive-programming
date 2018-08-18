#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  long long from = 1, to = k/2;
  if ((k & 1) == 0)
    --to;
  long long l = k - to, r = k - from;
  if (n < l) {
    puts("0");
    return 0;
  }
  r = min(n, r);
  from = max(from, k - r);
  long long ans = to - from + 1;
  ans = max(ans, 0LL);
  cout << ans << endl;

  return 0;
}