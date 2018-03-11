#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bool dp[N][3];
int pr[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i < N; ++i) if (pr[i] == 0) {
    for (int j = i; j < N; j += i)
      pr[j] = i;
  }
  int ans = n;
  for (int i = n-pr[n]+1; i <= n; ++i) {
    if (pr[i] != i) {
      ans = min(ans, i - pr[i] + 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}