#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, sz[N*N], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
char s[N][N];
int com[N][N];

int flood(int x, int y, int no) {
  s[x][y] = 'X';
  com[x][y] = no;
  int ret = 1;
  for(int i = 0; i<4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if(xx < n && xx >= 0 && yy < m && yy >= 0 && s[xx][yy] == '.') {
      ret += flood(xx, yy, no);
    }
  }
  ret %= 10;
  return ret;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++)
    scanf("%s", s[i]);
  int ncom = 0;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++) if(s[i][j] == '.') {
      ncom++;
      sz[ncom] = flood(i, j, ncom);
    }
  }
  for(int i = 0; i<n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'X')
        printf(".");
      else {
        set< int > st;
        for(int k = 0; k<4; k++) {
          int xx = i + dx[k], yy = j + dy[k];
          if(xx < n && xx >= 0 && yy < m && yy >= 0 && s[xx][yy])
            st.insert(com[xx][yy]);
        }
        int ans = 1;
        for(auto it = st.begin(); it != st.end(); it++)
          ans += sz[*it];
        ans %= 10;
        printf("%d", ans);
      }
    }
    printf("\n");
  }
  return 0;
}