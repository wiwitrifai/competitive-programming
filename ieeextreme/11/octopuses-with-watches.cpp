#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int a[N][N];
int n, m;
int x[N], cnt[3];

int solve(int id) {
  if (id == n) {
    int ans = 0;
    for (int i = 0; i < m; i++) {
      memset(cnt, 0, sizeof cnt);
      for (int j = 0; j < n; j++) {
        int z = a[j][i] + x[j];
        if (z >= 3)
          z -= 3;
        cnt[z]++;
      }
      ans += max(cnt[0], max(cnt[1], cnt[2]));
    }
    return ans;
  }
  else {
    int ans = 0;
    for (x[id] = 0; x[id] < 3; x[id]++)
      ans = max(ans, solve(id+1));
    return ans;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", a[i]+j);
      a[i][j] %= 3;
    }
  }
  printf("%d\n", solve(0));
  return 0;
}