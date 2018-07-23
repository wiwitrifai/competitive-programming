#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), sum += a[i];
  long long cur = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    if (cur * 2 >= sum) {
      ans = i+1;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}