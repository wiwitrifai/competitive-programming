#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N], cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  long long ans = 0;
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (a[i] + a[j] >= N) continue;
      ans += cnt[a[i] + a[j]];
    }
    cnt[a[i]]++;
  }
  printf("%d\n", ans);
  return 0;
}