#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 6, mod = 1e9 + 7;
int to[N][26], node;
int id[N];
void add(string & s, int v) {
  int now = 1, len = s.size();
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'a';
    if (!to[now][c])
      to[now][c] = node++;
    now = to[now][c];
  }
  id[now] = v;
}

char s[N];

int bit[N];
int get(int x) {
  int r = 0; 
  for (; x; x -= x & -x)
    r += bit[x];
  return r;
}
void upd(int x, int v) {
  for (; x < N; x += x & -x)
    bit[x] += v;
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}
string str[N];
int main() {
  int n, k;
  node = 2;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    str[i] = s;
  }
  sort(str, str+n);
  for (int i = 0; i < n; ++i) {
    add(str[i], i+1);
    upd(i+1, 1);
  }
  scanf("%s", s);
  int len = 0;
  long long ans = 1;
  long long mul = 1;
  for (int i = 0; i < k; ++i)
    mul = (mul * (n-i)) % mod;
  for (int i = 0, j = 0; i < k; ++i) {
    mul = mul * powmod((n-i), mod-2) % mod;
    int now = 1;
    while (id[now] == 0) {
      int c = s[j] - 'a';
      now = to[now][c];
      ++j;
    }
    ans = (ans + mul * (get(id[now])-1)) % mod;
    upd(id[now], -1);
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  printf("%lld\n", ans);
  return 0;
}