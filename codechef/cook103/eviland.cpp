#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long powmod(long long b, long long p, int m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int cnt[N];
int pw[N], a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, f;
    scanf("%d %d %d", &n, &m, &f);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    if (f == 0) {
      int ans = 0;
      for (int i = 0; i < n; ++i)
        ans += a[i] == 0;
      printf("%d\n", ans);
      continue;
    }
    int g = 1;
    int euler = m-1;
    vector<int> fact_euler;
    for (int i = 1; i < euler; ++i) {
      if (euler % i) continue;
      fact_euler.push_back(i);
    }
    while (g < m) {
      bool ok = 1;
      for (int u : fact_euler) {
        if (powmod(g, u, m) == 1) {
          ok = 0;
          break;
        }
      }
      if (ok) break;
      ++g;
    }
    assert(g < m);
    int now = 1;
    for (int i = 0; i < euler; ++i) {
      pw[now] = i;
      now = now * g % m;
    }
    memset(cnt, 0, sizeof cnt);
    int zero = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0)
        ++zero;
      else {
        ++cnt[gcd(euler, pw[a[i]])];
      }
    }
    f = gcd(euler, pw[f]);
    int ans = n;
    for (int i = 1; i <= euler; ++i) {
      if (f % i) {
        for (int j = i+i; j <= euler; j += i)
          cnt[i] += cnt[j];
        ans = min(ans, n - zero - cnt[i]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}