#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int dp[N], to[N];
int last[N][26];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < 26; i++)
    last[n][i] = n;
  dp[n] = 1;
  for (int i = n-1; i >= 0; i--) {
    int now = s[i] - 'a';
    to[i] = 0;
    for (int j = 0; j < 26; j++) {
      last[i][j] = last[i+1][j];
      if (dp[last[i][j]] < dp[last[i][to[i]]])
        to[i] = j;
    }
    dp[i] = dp[last[i][to[i]]] + 1;
    last[i][now] = i;
  }
  int ans = 0, cur = 0;
  for (int i = 0; i < 26; i++) {
    if (dp[last[0][i]] < dp[last[0][ans]])
      ans = i;
  }
  cur = last[0][ans];
  while (cur < n) {
    printf("%c", ans + 'a');
    ans = to[cur];
    cur = last[cur+1][ans];
  }
  printf("%c\n", ans + 'a');
  return 0;
}