#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int pre[N][11];
char b[11][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 10; i++)
    scanf("%s", b[i]);
  pre[0][9] = 9;
  for (int i = 0; i < 9; i++)
    pre[0][i] = -1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      pre[i][j] = -1;
      if (b[j][i] == 'X')
        continue;
      if (j < 9 && pre[i-1][j+1] >= 0) {
        pre[i][j] = j+1;
        continue;
      }
      if (((j == 9 || ((b[j+1][i-1] == 'X' && b[j+1][i] == 'X')))) && pre[i-1][j] >= 0) {
        pre[i][j] = j;
        continue; 
      }
      if ((j > 0 && pre[i-1][j-1] >= 0))
        pre[i][j] = j-1;
    }
  }
  vector< pair<int, int > > ans;
  int now = 0;
  while (now < 10 && pre[n-1][now] == -1) now++;
  int cnt = 0;
  for (int i = n-1; i >= 0; i--) {
    int nx = pre[i][now];
    if (nx > now) {
      cnt++;
    }
    else if (cnt) {
      ans.push_back({i, cnt});
      cnt = 0;
    }
    now = nx;
  }
  if (cnt) {
    ans.push_back({0, cnt});
  }
  printf("%d\n", ans.size());
  for (int i = (int)ans.size() - 1; i >= 0; i--) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}