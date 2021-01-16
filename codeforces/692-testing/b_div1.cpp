#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int n, cnt[N][2];

long long pre[N][2];
long long suf[N][2];

int main() {
  scanf("%s", s);
  n = strlen(s);
  long long cost[2];
  scanf("%lld %lld", cost, cost+1);
  cnt[0][0] = cnt[0][1] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j)
      cnt[i+1][j] = cnt[i][j];
    if (s[i] != '?') {
      ++cnt[i+1][s[i]-'0'];
    }
  }
  pre[0][0] = 0;
  pre[0][1] = 0;
  int c[2], b[2];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      pre[i+1][j] = pre[i][j];
      c[0] = c[1] = 0;
      for (int k = 0; k < 2; ++k)
        c[k] = cnt[i+1][k];
      int rest = (i+1) - (c[0] + c[1]);
      c[j] += rest;
      int select = j;
      if (s[i] == '0')
        select = 0;
      else if (s[i] == '1')
        select = 1;
      pre[i+1][j] += c[select^1] * cost[select^1];
    }
  }

  suf[n][0] = suf[n][1] = 0;
  long long ans = min(pre[n][0], pre[n][1]);
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < 2; ++j) {
      suf[i][j] = suf[i+1][j];
      c[0] = c[1] = 0;
      for (int k = 0; k < 2; ++k)
        c[k] = cnt[n][k] - cnt[i][k];
      int rest = (n - i) - (c[0] + c[1]);
      c[j] += rest;
      int select = j;
      if (s[i] == '0')
        select = 0;
      else if (s[i] == '1')
        select = 1;
      suf[i][j] += c[select^1] * cost[select];


      b[0] = b[1] = 0;
      for (int k = 0; k < 2; ++k)
        b[k] = cnt[i][k];
      rest = i - (b[0] + b[1]);
      b[j^1] += rest;
      long long add = cost[0] * b[0] * c[1] + cost[1] * b[1] * c[0];
      ans = min(ans, suf[i][j] + pre[i][j^1] + add);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
