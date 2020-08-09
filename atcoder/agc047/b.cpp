#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int to[N][26];
int dp[N][26];
int leaf[N];

int nodes = 1;

char s[N];

int ada[N][26];

long long dfs(int now) {
  long long ret = 0;
  for (int i = 0; i < 26; ++i) {
    if (to[now][i] == 0) continue;
    int u = to[now][i];
    if (leaf[u]) {
      ret += leaf[u] * (dp[now][i] - 1);
    }
    ret += dfs(u);
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    int now = 1;
    for (int j = 0; j < 26; ++j)
      ada[0][j] = 0;
    for (int j = 0; j < len; ++j) {
      s[j] -= 'a';
      for (int k = 0; k < 26; ++k) {
        ada[j+1][k] = ada[j][k];
      }
      ada[j+1][s[j]] = 1;
    }
    for (int k = 0; k < 26; ++k)
      dp[now][k] += ada[len][k];
    for (int j = len-1; j >= 0; --j) {
      if (to[now][s[j]] == 0) {
        to[now][s[j]] = ++nodes;
      }
      now = to[now][s[j]];
      for (int k = 0; k < 26; ++k) {
        dp[now][k] += ada[j][k];
      }
    }
    ++leaf[now];
  }
  printf("%lld\n", dfs(1));
  return 0;
}
