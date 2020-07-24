#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int nmask = 1 << 20, inf = 1e9 + 7;

char s[N], t[N];

int dp[nmask];
int to[22], ins[22];

void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s %s", s, t);
  memset(ins, 0, sizeof ins);
  for (int i = 0; i < 20; ++i)
    to[i] = 1 << i;
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    int u = s[i] - 'a', v = t[i] - 'a';
    to[u] |= 1 << v;
    ins[v] |= 1 << u;
  }
  while (true) {
    bool done = true;
    for (int i = 0; i < 20; ++i) {
      for (int j = 0; j < 20; ++j) {
        if (to[i] & (1 << j)) {
          if (to[i] != to[j]) {
            done = false;
            to[i] = to[j] = to[i] | to[j];
          }
        }
      }
    }
    if (done)
      break;
  }
  for (int i = 0; i < 20; ++i) {
    if (to[i] & (1 << i))
      to[i] ^= 1 << i;
  }
  dp[0] = 0;
  for (int j = 1; j < nmask; ++j)
    dp[j] = inf;
  for (int mask = 0; mask < nmask; ++mask) {
    int rev = (nmask - 1) ^ mask;
    for (int i = 0; i < 20; ++i) {
      if ((mask >> i) & 1) continue;
      int out = to[i] & rev, mins = ins[i] & rev;
      int cost = (out > 0) + (mins > 0);
      int nxt = mask | (1 << i);
      dp[nxt] = min(dp[nxt], dp[mask] + cost);
    }
  }
  printf("%d\n", dp[nmask-1]);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
