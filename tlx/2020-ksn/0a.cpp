#include <bits/stdc++.h>

using namespace std;

int powmod(int x, int y, int m) {
  int r = 1;
  for (; y; y >>= 1, x = 1LL * x * x % m)
    if (y & 1)
      r = 1LL * r * x % m;
  return r;
}

int calc(int a, int b, int m) {
  if ((a % m) == 0)
    return 0;
  if (b == 0)
    return 1;
  if (b == 1)
    return a % m;
  if (b == 2)
    return powmod(a, a, m);
  if ((a % m) == 1)
    return 1;
  int cnt = 1;
  map<int, int> pw;
  vector<int> pattern;
  pw[1] = 0;
  pattern.push_back(1);
  int now = a % m;
  while (pw.find(now) == pw.end()) {
    pattern.push_back(now);
    pw[now] = cnt;
    ++cnt;
    now = 1LL * now * a % m;
  }
  int cycle = cnt - pw[now];
  int res = calc(a, b-1, cycle);
  int offset = cnt - cycle;
  res = (res - offset) % cycle;
  res = (res + cycle) % cycle;
  return pattern[offset + res];
}

int main() {
  int a, b, m;
  scanf("%d %d %d", &a, &b, &m);
  printf("%d\n", calc(a, b, m));
  return 0;
}
