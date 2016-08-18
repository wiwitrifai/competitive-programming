#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector< pair< long long, long long > > val; 

int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = ((m % mod) * (n % mod)) % mod;
  for (long long a = 1; a * a <= n; a++) {
    val.push_back({a, n/a});
    val.push_back({n/a, a});
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  long long now = 1;
  long long inv2 = (mod + 1)/2;
  for (int i = 0; i < val.size(); i++) {
    long long next = min(val[i].first, m);
    long long nn = (next - now + 1) % mod, sum = (now + next) % mod;
    long long tmp = val[i].second % mod;
    ans -= (((((nn * sum) % mod) * inv2) % mod) * tmp) % mod;
    ans %= mod;
    if (ans < 0)
      ans += mod;
    now = next + 1;
    if (now > m)
      break;
  }
  cout << ans << endl;
 
  return 0;
}