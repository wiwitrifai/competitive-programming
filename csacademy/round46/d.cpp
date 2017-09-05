#include <bits/stdc++.h>

using namespace std;

const int N = 2017;

char s[N][N];
int h[N][N], v[N][N], g[N][N], ul[N][N], dr[N][N], n, m;

long long ans = 0;
int bit[N];
void upd(int x, int val) {
  for (; x; x -= x &-x)
    bit[x] += val;
} 
int get(int x) {
  int ret = 0;
  for (; x < N; x += x&-x)
    ret += bit[x];
  return ret;
}
vector<int> rem[N];
void process(int x, int y) {
  memset(bit, 0, sizeof bit);
  int z = 1;
  for (int i = 1;; i++, x++, y++) {
    if (x >= n || y >= m) break;
    upd(i, 1);
    rem[ul[x][y] + i].push_back(i);
    z = max(z, ul[x][y] + i);
    for (int d : rem[i])
      upd(d, -1);
    ans += get(i-dr[x][y]+1);
  }
  for (int i= 1; i <= z; i++)
    rem[i].clear();
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++)
      s[i][j] -= '0';
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = m-1; j >= 0; j--) {
      v[i][j] = h[i][j] = g[i][j] = 0;
      if (!s[i][j]) continue;
      h[i][j] = 1 + (j+1 < m ? h[i][j+1] : 0);
      v[i][j] = 1 + (i+1 < n ? v[i+1][j] : 0);
      g[i][j] = 1 + (i+1 < n && j+1 < m ? g[i+1][j+1] : 0);
      ul[i][j] = min(h[i][j], min(v[i][j], g[i][j]));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v[i][j] = h[i][j] = g[i][j] = 0;
      if (!s[i][j]) continue;
      h[i][j] = 1 + (j-1 >= 0 ? h[i][j-1] : 0);
      v[i][j] = 1 + (i-1 >= 0 ? v[i-1][j] : 0);
      g[i][j] = 1 + (i-1 >= 0 && j-1 >= 0 ? g[i-1][j-1] : 0);
      dr[i][j] = min(h[i][j], min(v[i][j], g[i][j]));
    }
  }
  ans = 0;
  for (int i = 0; i < n; i++)
    process(i, 0);
  for (int j = 1; j < m; j++)
    process(0, j);
  printf("%lld\n", ans);
  return 0;
}