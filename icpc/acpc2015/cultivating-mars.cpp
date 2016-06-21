#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, M = 2e5 + 5;

#define x first
#define y second

typedef pair< long long, long long > point;

long long operator*(point a, point b) {
  return a.x * b.x + a.y * b.y;
}

bool cmp(pair<point, int> a, pair<point, int >b ) {
  long long crs = a.x.x * b.x.y - a.x.y * b.x.x;
  // if(crs == 0) {
  //   long long da = a.x*a.x, db = b.x*b.x;
  //   return da > db;
  // }
  return (crs) > 0;
}

point con[N];
pair< point, int > que[M];
long long ans[M];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i<n; i++) {
      long long x, y;
      scanf("%lld%lld", &x, &y);
      con[i] = make_pair(x, y);
    }
    con[n] = con[0];
    int m = 0;
    for(int i = 0; i<q; i++) {
      long long x, y;
      scanf("%lld%lld", &x, &y);
      if(x == 0 && y == 0)
        ans[i] = 0;
      else
        que[m++] = make_pair(make_pair(x, y), i);
    }
    que[m++] = make_pair(make_pair(con[0].x-con[n-1].x, con[n-1].y-con[0].y), -1);
    que[m++] = make_pair(make_pair(con[n-1].x-con[0].x, con[0].y-con[n-1].y), -1);
    for(int i = 1; i<n; i++) {
      que[m++] = make_pair(make_pair(con[i].x-con[i-1].x, con[i-1].y-con[i].y), -1);
      que[m++] = make_pair(make_pair(con[i-1].x-con[i].x, con[i].y-con[i-1].y), -1);
    }
    sort(que, que+m);
    int k = 0;
    while(k < m && (que[k].x.x < 0 || (que[k].x.x == 0 && que[k].x.y < 0))) k++;
    sort(que, que+k, cmp);
    sort(que+k, que+m, cmp);
    k = 0;
    for(int i = 1; i<n; i++)
      if(que[0].x*con[k] < que[0].x*con[i])
        k = i;
    if(que[0].y>-1)
      ans[que[0].y] = que[0].x*con[k];
    for(int i = 1; i<m; i++) {
      while(que[i].x*con[k] < que[i].x*con[(k+1) % n]) k = (k+1) % n;
      if(que[i].y > -1)
        ans[que[i].y] = que[i].x*con[k];
    }
    for(int i = 0; i<q; i++)
      printf("%lld\n", ans[i]);
  }
  return 0;
}