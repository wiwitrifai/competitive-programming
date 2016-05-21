#include <bits/stdc++.h>

using namespace std;

int n, k;
char s[33][33];
int dx[] = {0, 1, 1, -1}, dy[] = {1, 0, 1, 1};

int main() {
int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++)
      scanf("%s", s[i]);
    bool found = false;
    for(int i = 0; i<n && !found; i++) {
      for(int j = 0; j<n && !found; j++) if(s[i][j] == '.') {
        for(int x = 0; x<4 && !found; x++) {
          int cnt = 1;
          for(int z = 1; i + z*dx[x] < n && j + z*dy[x] < n && i + z*dx[x] >= 0 && j + z*dy[x] >= 0; z++) {
            if(s[i + z*dx[x]][j + z*dy[x]] == 'X')
              cnt++;
            else
              break;
          }
          for(int z = 1; i - z*dx[x] < n && j - z*dy[x] < n && i - z*dx[x] >= 0 && j - z*dy[x] >= 0; z++) {
            if(s[i - z*dx[x]][j - z*dy[x]] == 'X')
              cnt++;
            else
              break;
          }
          found |= cnt >= k;
        }
      }
    }
    puts(found ? "YES" : "NO");
  }
  return 0;
}