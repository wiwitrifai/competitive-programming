#include <bits/stdc++.h>

using namespace std;

const int N = 505;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > ans)
      ans = a[i];
    for (int j = i+1; j < n; ++j) {
      long long cur = a[i] | a[j];
      if (cur > ans)
        ans = cur;
      for (int k = j+1; k < n; ++k) {
        long long now = cur | a[k];
        if (now > ans)
          ans = now;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
