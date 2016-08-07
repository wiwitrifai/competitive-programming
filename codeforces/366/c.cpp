#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int to[N][2], a[N][2], n, m, used[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i<=n; i++) {
    int cnt;
    scanf("%d", &cnt);
    a[i][0] = a[i][1] = 0;

    for(int j = 0; j<cnt; j++) {
      scanf("%d", a[i]+j);
      int now = abs(a[i][j]);
      to[now][used[now]++] = i;
    }
  }
  long long ans = 1;
  for(int i = 0; i<m; i++) if(

  }
  return 0;
}