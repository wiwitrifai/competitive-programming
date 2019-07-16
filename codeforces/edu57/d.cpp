#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const long long inf = 1e18;

int a[N];
char s[N];
char hard[] = "hard";
long long ans[5], tmp[5];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < 5; ++i)
    ans[i] = inf;
  ans[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j)
      tmp[j] = min(ans[j] + a[i], inf);
    for (int j = 0; j < 4; ++j) {
      int to = j;
      if (s[i] == hard[j]) ++to;
      tmp[to] = min(tmp[to], ans[j]);
    }
    for (int j = 0; j < 5; ++j)
      ans[j] = tmp[j];
  }
  long long best = ans[0];
  for (int i = 0; i < 4; ++i)
    best = min(best, ans[i]);
  printf("%lld\n", best);
  return 0;
}