#include "table.h"

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, X = 100;

long long r[X];
void add(long long a[X], long long b[X]) {
  memset(r, 0, sizeof r);
  for (int i = 0; i < X; ++i) {
    for (int j = 0; j < X; ++j) {
      int s = (i+j) % X;
      r[s] = (r[s] + 1LL * a[i] * b[j]) % mod;
    }
  }
  for (int i = 0; i < X; ++i)
    a[i] = r[i];
}

long long r2[X];
void multiple(long long a[X], long long mul) {
  memset(r2, 0, sizeof r2);
  r2[0] = 1;
  for (; mul; mul >>= 1, add(a, a))
    if (mul & 1)
      add(r2, a);
  for (int i = 0; i < X; ++i)
    a[i] = r2[i];
}

long long dp[X];
long long a[X];
long long cnt[X];
int pw[X][X+X];
int used[X];

int countSubsets(int M, int N, int K, std::vector<int> C, std::vector<int> D) {
  int euler = (4 - 2) * (25 - 5);
  memset(cnt, 0, sizeof cnt);
  for (int r = 1; r <= X; ++r) {
    if (r > M) break;
    long long ver = (M-r)/X + 1;
    int now = r % X;
    memset(used, 0, sizeof used);
    for (int i = 1; i <= N; ++i, now = now * r % X) {
      if (used[now]) {
        int cyc = i - used[now];
        int cur = N - i;
        for (int j = 0; j < cyc; ++j, now = now * r % X) {
          if (cur < j) break;
          int hor = (cur - j) / cyc + 1;
          cnt[now] += 1LL * ver * hor;
        } 
        break;
      }
      used[now] = i;
      cnt[now] += ver;
    }
  }
  for (int i = 0; i < X; ++i) {
    memset(used, 0, sizeof used);
    for (int j = 0, now = 1; j < X+X; ++j, now = now * i % X) {
      pw[i][j] = now;
    }
  }
  for (int i = 0; i < K; ++i) {
    int c = C[i] % X;
    int p = D[i];
    p %= euler;
    while (p + euler <= min(D[i], X+X-1)) p += euler;
    int cur = pw[c][p];
    --cnt[cur];
  }
  memset(dp, 0, sizeof dp); dp[0] = 1;
  for (int i = 0; i < X; ++i) {
    memset(a, 0, sizeof a);
    ++a[i];
    ++a[0];
    multiple(a, cnt[i]);
    add(dp, a);
  }
  return dp[13] % mod;
}
