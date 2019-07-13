#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long p[N];

int main() {
  long long n, k;
  int m;
  scanf("%lld %d %lld", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%lld", p+i);
    --p[i];
  }
  int ans = 0;
  for (int i = 0; i < m;) {
    int rem = i;
    long long cur = p[i] - rem;
    long long page = cur / k;
    long long til = 1LL * (page + 1) * k + rem;
    int j = i;
    while (j < m && p[j] < til) {
      ++j;
    }
    ++ans;
    i = j;
  }
  printf("%d\n", ans);
  return 0;
}
