#include <bits/stdc++.h>

using namespace std;

const int N =20;
int n, m;
char s[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++)
      scanf("%s", s[i]);
    int ans = 0;
    for(int i = 0; i<m; i++) {
      int cnt = 0;
      for(int j = 0; j<n; j++)
        cnt += (s[j][i] == '1');
      ans += cnt * (cnt-1) / 2;
    }
    printf("%d\n", ans);
  }
  

  return 0;
}