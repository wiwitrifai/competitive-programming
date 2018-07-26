#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

const int N = 1e6 + 5;

int ans[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int all = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int v = gcd(a % k, k) % k;
    all = gcd(v, all);
    ans[v] = 1;
  }
  ans[all] = 1;
  ans[0] = 1;
  for (int i = 1; i < k; ++i) {
    if (!ans[i]) continue;
    for (int j = i; j < k; j += i)
      ans[j] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < k; ++i)
    cnt += ans[i];
  printf("%d\n", cnt);
  for (int i = 0; i < k; ++i)
    if (ans[i])
      printf("%d ", i);
  printf("\n");
  return 0;
}