#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
char s[N];
int sum[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  sum[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + (s[i] == '#');
  }
  int ans = n;
  for (int i = 0; i <= n; ++i) {
    int black = sum[i];
    int white = (n-i) - (sum[n]-sum[i]);
    ans = min(ans, black + white);
  }
  printf("%d\n", ans);
  return 0;
}
