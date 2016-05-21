#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m, dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int x[N][N];
int y[N][N];
char s[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    queue<pair<int, int>> q;
    memset(x, 0, sizeof x);
    for(int i = 0; i<n; i++) {
      scanf("%s", s+i);
      for(int j = 0; j<m; j++) if(s[i][j] == '*') {
        x[i][j] = 1;
        q.push({i, j});
      }
    }
    while(!q.empty()) {
      int a = q.front().first, b = q.front().second;
      q.pop();
      for(int i = 0; i<4; i++) {
        int aa = a + dx[i], bb = b + dy[i];
        if(aa < n && aa >= 0 && bb < m && bb >= 0 && x[aa][bb] == 0 && s[aa][bb] != '#') {
          x[aa][bb] = x[a][b] + 1;
          q.push({aa,bb});
        }
      }
    }
    memset(y, 0, sizeof y);
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++)
        if(s[i][j] == 'S') {
          y[i][j] = 1;
          q.push({i, j});
          break;
        }
    bool found = false;
    while(!q.empty()) {
      int a = q.front().first, b = q.front().second;
      if(s[a][b] == 'X') {
        found = true;
        break;
      }
      q.pop();
      int val = y[a][b] + 1;
      for(int i = 0; i<4; i++) {
        int aa = a + dx[i], bb = b + dy[i];
        if(aa < n && aa >= 0 && bb < m && bb >= 0 && (x[aa][bb] > val || x[aa][bb] == 0) && s[aa][bb] != '#' && y[aa][bb] == 0) {
          y[aa][bb] = val;
          q.push({aa,bb});
        }
      }
    }
    puts(found ? "yes" : "no");
  }
  return 0;
}