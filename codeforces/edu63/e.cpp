#include <bits/stdc++.h>

using namespace std;

const int N = 11, mod = 1e6 + 3;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long inv(int x) {
  return powmod(x, mod-2);
}

int grid[N][N+1];

void answer(int x) {
  printf("! %d\n", x);
  exit(0);
}

int ask(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == -1)
    exit(0);
  if (res == 0) {
    answer(x);
  }
  return res;
}

int a[N+1];

int main() {
  for (int m = 0; m < N; ++m) {
    for (int j = 0, now = 1; j < N; ++j, now = 1LL * now * m % mod) {
      grid[m][j] = now;
    }
    grid[m][N] = ask(m);
    for (int j = 0; j < m; ++j) {
      if (grid[m][j] == 0) continue;
      int mul = grid[m][j] % mod;
      for (int k = 0; k <= N; ++k) {
        grid[m][k] = (grid[m][k] - 1LL * grid[j][k] * mul) % mod;
        if (grid[m][k] < 0)
          grid[m][k] += mod;
      }
    }
    int cur = inv(grid[m][m]);
    for (int j = 0; j <= N; ++j) {
      grid[m][j] = 1LL * cur * grid[m][j] % mod;
    }
    assert(grid[m][m] == 1);
    for (int j = 0; j < m; ++j) {
      if (grid[j][m] == 0) continue;
      int mul = grid[j][m] % mod;
      for (int k = 0; k <= N; ++k) {
        grid[j][k] = (grid[j][k] - 1LL * grid[m][k] * mul) % mod;
        if (grid[m][k] < 0)
          grid[j][k] += mod;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    a[i] = grid[i][N];
  }
  for (int i = 0; i < mod; ++i) {
    long long cur = 0;
    for (int j = 0, now = 1; j < N; ++j, now = 1LL * now * i % mod) {
      cur = (cur + 1LL * now * a[j]) % mod;
    }
    if (cur == 0)
      answer(i);
  }
  answer(-1);
  return 0;
}
