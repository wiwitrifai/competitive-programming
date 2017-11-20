#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long a[N];
long long tot[N];
vector<int> d[N], divisor[N];
set<int> mul[N];

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    scanf("%lld", a+i), ans += a[i];
  for (int i = n; i > 0; i--) {
    tot[i] = 0;
    for (int j = i; j <= n; j += i) {
      tot[i] += a[j];
      divisor[j].push_back(i);
      mul[i].insert(j);
    }
  }
  for (int i = n; i > 0; i--) {
    if (tot[i] < 0) {
      ans -= tot[i];
      for (int u : mul[i]) {
        for (int d : divisor[u]) {
          tot[d] -= a[u];
          mul[d].erase(u);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}