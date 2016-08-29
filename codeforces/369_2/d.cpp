#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}
int p[N], a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", p+i), p[i]--;
  long long ans = 1;
  int stmp = 0;
  for (int i = 0; i < n; i++) if (a[i] == 0) {
    int now = i;
    int cnt = 0;
    while (a[now] == 0) {
      a[now] = ++stmp;
      now = p[now];
      cnt++;
    }
    if (a[now] > 0) {
      int cir = stmp - a[now] + 1;
      ans = (ans * (powmod(2, cir) - 2)) % mod;
      if (ans < 0)
        ans += mod;
      cnt -= cir;
    }
    ans = (ans * powmod(2, cnt)) % mod;
    now = i;
    while (a[now] > 0) {
      a[now] = -1;
      now = p[now];
    }
  }
  cout << ans <<  endl;
  return 0;
}