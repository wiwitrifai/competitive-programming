#include <bits/stdc++.h>

using namespace std;

map<long long, long long> mem;
const long long inf = 2e18;

long long n, a, b, c, d;

void upd(long long & var, long long x) {
  if (var == -1 || var > x)
    var = x;
}
long long calc(long long v) {
  if (v <= 0)
    return 0;
  auto it = mem.find(v);
  if (it != mem.end()) {
    return it->second;
  }
  long long res = -1;
  if (inf / d >= v) {
    res = d * v;
  }
  for (int i = -5; i <= min(5LL, v); ++i) {
    long long cur = v - i;
    if ((cur % 5) == 0 &&  cur / 5 < v) {
      upd(res, calc(cur/5) + c + d * abs(i));
      // break;
    }
  }
  for (int i = -5; i <= min(5LL, v); ++i) {
    long long cur = v - i;
    if ((cur % 3) == 0 &&  cur / 3 < v) {
      upd(res, calc(cur/3) + b + d * abs(i));
      // break;
    }
  }
  for (int i = -5; i <= min(5LL, v); ++i) {
    long long cur = v - i;
    if ((cur % 2) == 0 && cur / 2 < v) {
      upd(res, calc(cur/2) + a + d * abs(i));
      // break;
    }
  }
  return mem[v] = res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cin >> n >> a >> b >> c >> d;
    mem.clear();
    cout << calc(n) << '\n';
  }
  return 0;
}
