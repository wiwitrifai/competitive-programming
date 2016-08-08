#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;
const int N = 303;
#define x first
#define y second

point p[N<<2];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int xa, xb, ya, yb;
    scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    for(int i = 0; i<4*n; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    xa *= 4; xb *= 4; ya *= 4; yb *= 4;
    int ans = 0;
    for(int i = 0; i<n; i++)
    for(int j = n; j<2*n; j++)
    for(int k = 2*n; k<3*n; k++)
    for(int l = 3*n; l<4*n; l++) {
      // if(p[i] != p[j] && p[i] != p[k] && p[i] != p[l] && p[j] != p[k] && p[j] != p[l] && p[k] != p[l]) {
        int sumx = p[i].x + p[j].x + p[k].x + p[l].x, sumy = p[i].y + p[j].y + p[k].y + p[l].y;
        if(sumx <= xb && sumx >= xa && sumy <= yb && sumy >= ya)
          ans++;
      // }
    } 
    cout << ans << endl;
  }

  return 0;
}