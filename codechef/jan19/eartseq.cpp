#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 4;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int a[N], ans[N], p[N];
int prime[] = {2, 3, 5, 7, 11};

int main() {
  a[0] = 1;
  for (int i = 1, j = 2; i < N; ++j) {
    if (gcd(j, a[i-1] * 30 * 77) != 1) continue;
    a[i++] = j;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int r = n % 4, k = n - r;
    for (int i = 0; i < k; ++i) {
      p[i] = prime[i % 4];
    }
    if (r == 1) {
      p[k] = prime[4];
    }
    else {
      for (int j = 0; j < r; ++j)
        p[k+j] = prime[j+1];
    }
    ans[0] = p[0] * p[n-1] * a[0];
    for (int i = 1; i < n; ++i)
      ans[i] = p[i] * p[i-1] * a[i];
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}