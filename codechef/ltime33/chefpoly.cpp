#include <bits/stdc++.h>

using namespace std;

const int N = 105, M = 3003, inf = 1e7;

#define x first
#define y second
pair<int, int > red[N], black[M];
int n, m, cnt[N][N], at[N][N];

int cross(pair<int, int> p, pair<int, int> q, pair<int, int> r) {
  return (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++)
    scanf("%d%d", &red[i].x, &red[i].y);
  for(int i = 0; i<m; i++)
    scanf("%d%d", &black[i].x, &black[i].y);
  sort(black, black+m);
  for(int i = 0; i<n; i++)
    for(int j = i+1; j<n; j++) {
      pair<int, int> left = red[i], right = red[j];
      if(left.x == right.x) {
        continue;
      }
      if(left.x > right.x)
        swap(left, right);
      int temp = 0;
      int l = lower_bound(black, black+m, make_pair(left.x, inf)) - black;
      int r = lower_bound(black, black+m, make_pair(right.x, inf)) - black;
      for(int k = l; k < r; k++) {
        int crs = cross(left, right, black[k]);
        if(crs > 0)
          temp++;
        if(crs == 0)
          at[i][j]++, at[j][i]++;
      }
      if(red[i].x > red[j].x)
        temp *= -1;
      cnt[i][j] = temp;
      cnt[j][i] = -temp;
    }
  int q;
  scanf("%d", &q);
  while(q--) {
    int k;
    int temp, prev, now;
    scanf("%d", &k);
    scanf("%d", &temp);
    temp--;
    now = temp;
    int ans = 0;
    while(--k) {
      prev = now;
      scanf("%d", &now);
      now--;
      ans += cnt[prev][now];
      if(red[prev].x > red[now].x)
        ans -= at[prev][now];
    }
    ans += cnt[now][temp];
    if(red[now].x > red[temp].x)
      ans -= at[now][temp];
    printf("%d\n", ans);
  }
  return 0;
}