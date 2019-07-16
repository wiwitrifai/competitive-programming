#include <bits/stdc++.h>

using namespace std;

long long powmod(long long b, long long p, long long mod) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

const int N = 1e6 + 6;

int s[N], ss[N];
bool isprime[N];
int pos[N];

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  fill(isprime+2, isprime+N, 1);
  for (int i = 2; i < N; ++i) {
    if (!isprime[i]) continue;
    for (int j = i+i; j < N; j += i)
      isprime[j] = 0; 
  }
  int p;
  long long l;
  scanf("%d %lld", &p, &l);
  int g = 2;
  int totient = p-1;
  vector<int> factor, pfact;
  for (int i = 1; i < totient; ++i) {
    if (totient % i) continue;
    factor.push_back(i);
    if (isprime[i])
      pfact.push_back(totient/i);
  }
  bool found = 0;
  while (!found && g < p) {
    found = 1;
    for (int x : pfact) {
      int v = powmod(g, x, p);
      if (v == 1) {
        found = 0;
        break;
      }
    }
    if (found) break;
    ++g;
  }
  assert(found);
  vector<int> gen(totient);
  memset(pos, -1, sizeof pos);
  for (int i = 0, now = 1; i < totient; ++i, now = 1LL * now * g % p) {
    gen[i] = now;
    pos[now] = i;
  }
  for (int a = 1; a < totient; ++a) {
    assert(pos[a] >= 0);
    int c = a + 1;
    if (c >= p) c -= p;
    if (pos[c] != -1) {
      int g = gcd(pos[a], pos[c]);
      g = gcd(g, totient);
      ss[g] = 1;
    }
    int b = 1 + p - a;
    if (b >= p) b -= p;
    if (pos[b] != -1) {
      int g = gcd(pos[a], pos[b]);
      g = gcd(g, totient);
      ss[g] = 1;
    }
  }
  for (int f : factor)
    if (ss[f] == 0) {
      for (int i = f; i < totient; i += f)
        ss[f] |= ss[i];
    }
  for (int f : factor)
    for (int i = f; i < totient; i += f)
      s[i] = ss[f];
  long long ans = 0;
  for (int i = 1; i < totient; ++i) {
    if (!s[i]) continue;
    if (i > l) break;
    ans += (l - i) / totient + 1;
  }
  printf("%lld\n", ans);
  return 0;
}