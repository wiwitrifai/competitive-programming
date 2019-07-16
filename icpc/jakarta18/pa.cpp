#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), sum += a[i];
  sort(a, a+n);
  int ans = 0;
  if (ans == a[0])
    ++ans;
  if (ans == a[n-1])
    ++ans;
  if (ans == sum)
    ++ans;
  printf("%d\n", ans);
  return 0;
}