#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector< int > fac[N];


int main() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j+= i)
      fac[j].push_back(i);
  }
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i, k = 0; j < n; j += i, k++) {
      int res = n-j;
      ans += fac[res].end() - upper_bound(fac[res].begin(), fac[res].end(), max(i, k));
    }
  }
  printf("%lld\n", ans);
  return 0;
}