#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, t;
  cin >> n >> t;
  long double ans = n, now;
  now = n;
  for(long long i = 0; i<t; i++) {
    if(i > 1e7)
      break;
    now *= (long double)(t-i)/(i+1);
    now *= 0.000000011;
    ans += now;
  }
  cout << setprecision(20) << fixed << ans << endl;
  return 0;
}