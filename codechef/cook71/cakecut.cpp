#include <bits/stdc++.h>

using namespace std;

const int N = 1524;

char s[N][N];
int n, m;
bitset< N > bs[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++)
    scanf("%s", s[i]);
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++) {
      bs[i+1][j+1] = (s[i][j] == '1') ^ bs[i+1][j] ^ bs[i][j+1] ^ bs[i][j];
    }
  }
  long long ans = 0;
  for(int i = 0; i<n; i++)
    for(int j = i+1; j<=n; j++) {
      int a = (bs[i] ^ bs[j]).count(), b = m+1-a;
      ans += 1LL * a * (a-1)/2 + 1LL * b * (b-1)/2;
    }
  printf("%lld\n", ans);
  return 0;
}
