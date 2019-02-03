#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

bitset<N> a, b;
int s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i)
      scanf("%d", s+i);
    sort(s, s+n);
    reverse(s, s+n);
    if (s[0] >= p) {
      for (int i = 0; i < n; ++i) {
        printf("%d%c", n, i == n-1 ? '\n' : ' ');
      }
      continue;
    }
    int one = n, two = n;
    long long sum = 0;
    p -= s[0];
    for (int i = 1; i < n; ++i) {
      sum += s[i];
      if (sum >= p)
        one = min(i, one);
    }
    if (sum >= 2 * p) {
      a.reset();
      b.reset();
      a[0] = 1;
      sum = 0;
      for (int i = 1, j = 0; i < n; ++i) {
        sum += s[i];
        a |= (a << s[i]);
        while (j < N && j <= sum - 2 * p) {
          b[j] = 1;
          ++j;
        }
        if (sum >= 2 * p && i > 1) {
          if (((a >> p) & b).any()) {
            two = i-1;
            break;
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int ans = max(n - two, 0);
      ans = max(i+1 - one, ans);
      ans = max(n-i - one, ans);
      printf("%d%c", ans, i==n-1? '\n' : ' ');
    }
  }
  return 0;
}