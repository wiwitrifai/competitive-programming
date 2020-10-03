#include <bits/stdc++.h>

using namespace std;

const int N = 212;

int dp[N];
int a[N], b[N];
int used[N];

int main() {
  int n;
  scanf("%d", &n);
  memset(used, -1, sizeof used);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
    if (a[i] > 0) {
      --a[i];
      if (used[a[i]] != -1) {
        puts("No");
        return 0;
      }
      used[a[i]] = i;
    }
    if (b[i] > 0) {
      --b[i];
      if (used[b[i]] != -1) {
        puts("No");
        return 0;
      }
      used[b[i]] = i;
    }
    if (a[i] != -1 && b[i] != -1) {
      if (a[i] >= b[i]) {
        puts("No");
        return 0;
      }
    }
  }
  dp[0] = true;
  for (int i = 0; i < 2 * n; ++i) {
    if ((i & 1) == 0) continue;
    for (int len = 1; len * 2 <= i + 1; ++len) {
      if (!dp[i+1 - len * 2]) continue;
      bool ok = true;
      for (int j = 0; j < len; ++j) {
        int rig = i - j, lef = rig - len;
        if (used[lef] != -1 && used[rig] != -1) {
          ok &= used[lef] == used[rig];
        } else if (used[lef] != -1) {
          ok &= b[used[lef]] == -1;
        } else if (used[rig] != -1) {
          ok &= a[used[rig]] == -1;
        }
      }
      if (ok) {
        dp[i+1] = true;
        break;
      }
    }
  }
  puts(dp[2 * n] ? "Yes" : "No");
  return 0;
}
