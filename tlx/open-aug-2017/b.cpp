#include <bits/stdc++.h>

using namespace std;

const int N = 202;

typedef pair<long long,long long> point;
#define x first
#define y second

int n;
point p[N];
long long cross(point a, point b, point c) {
  return (a.x-b.x) *(c.y-b.y) - (a.y-b.y)*(c.x-b.x);
}

int cnt[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &p[i].first, &p[i].second);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt[i][j] = 0;
      point a = p[i], b = p[j];
      if (a.x > b.x)
        swap(a, b);
      for (int k = 0; k < n; k++) {
        if (p[k].x < a.x || p[k].x > b.x) continue;
        if (cross(a, b, p[k]) < 0) continue;
        if (i == j && p[k].y > p[i].y) continue;
        cnt[i][j]++;
      }
      // cerr << i << " " << j << " " << cnt[i][j] << endl;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        vector<pair<point, int>> vp = {{p[i], i}, {p[j], j}, {p[k], k}};
        sort(vp.begin(), vp.end());
        long long cur = 0;
        if (cross(vp[0].x, vp[2].x, vp[1].x) > 0) {// satu bawah
          cur = cnt[vp[0].y][vp[2].y] - cnt[vp[0].y][vp[1].y] - cnt[vp[1].y][vp[2].y] + cnt[vp[1].y][vp[1].y];
        }
        else {
          cur = cnt[vp[0].y][vp[1].y] + cnt[vp[1].y][vp[2].y] - cnt[vp[0].y][vp[2].y] - cnt[vp[1].y][vp[1].y] - 1;
        }
        // cerr << i << " " << j << " " << k << " " << cur << endl;
        ans += cur;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}