#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, M = 26;
const int mod = 1e9 + 7;

char s[N];
long long a[M], b[M][M], c[M][M];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    int x = s[i]-'a';
    for(int j = 0; j<M; j++)
      ans = (ans + c[x][j]) % mod;
    for(int j = 0; j<M; j++)
      c[j][x] = (c[j][x] + b[j][x]) % mod;
    for(int j = 0; j<M; j++)
      b[j][x] = (b[j][x] + a[j]) % mod;
    a[x]++;
  }
  printf("%lld\n", ans);
  return 0;
}