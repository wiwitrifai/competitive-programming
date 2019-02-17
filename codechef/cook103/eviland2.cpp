#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int isp[N];
vector<int> vp[N];

long long powmod(long long b, long long p, int m) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      r = r * b % m;
  return r;
}

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i+i; j < N; j += i)
      vp[j].push_back(i);
  }
  for (int i = 3; i < N; ++i) {
    if (vp[i].size() > 1) continue;
    int g = 2;
    while (g < i) {
      bool ok = 1;
      for (int u : vp[i-1])
        if (powmod(g, u, i) == 1) {
          ok = 0;
          break;
        }
      if (ok)
        break;
      ++g;
    }
    assert(g < i);
  }
  return 0;
}