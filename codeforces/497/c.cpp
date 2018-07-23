#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

vector<pair<long long, long long > > unknown;

int ask(long long x, long long y) {
  for (auto it : unknown) {
    if (x >= it.first && y >= it.second)
      return 3;
  }
  ++cnt;
  assert(cnt <=  600);
  printf("%lld %lld\n", x, y);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == 0)
    exit(0);
  else if (res == 3)
    unknown.emplace_back(x, y);
  assert(unknown.size() <= 600);
  return res;
}

int main() {
  long long n;
  scanf("%lld", &n);
  long long x = 1, y = 1;
  while (1) {
    long long a = x, b = n;
    long long p = y, q = n;
    bool change = 0;
    while (a < b && p < q) {
      long long c = (a + b) >> 1;
      long long r = (p + q) >> 1;
      int res = ask(c, r);
      if (res == 1) {
        x = a = c + 1;
        b = max(b, a);
        change = 1;
      }
      else if (res == 2) {
        y = p = r + 1;
        q = max(p, q);
        change = 1;
      }
      else {
        b = c;
        q = r;
      }
    }
    if (!change) break;
  }
  {
    long long a = x, b = n;
    while (a < b) {
      long long c = (a + b) >> 1;
      int res = ask(c, y);
      if (res == 1) {
        x = a = c + 1;
      }
      else {
        if (res == 2)
          ++y;
        b = c;
      }
    }
  }
  {
    long long p = y, q = n;
    while (p < q) {
      long long r = (p + q) >> 1;
      int res = ask(x, r);
      if (res == 2) {
        y = p = r + 1;
      }
      else {
        if (res == 1)
          ++x;
        q = r;
      }
    }
  }
  ask(x, y);
  cout << " done " << endl;
  fflush(stdout);
  assert(false);
  return 0;
}