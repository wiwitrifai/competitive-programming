#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef pair<long long, long long> point;
#define x first
#define y second

const long long inf = 7e18 + 9;
long long sum[N];
long long ma[N], mi[N];
point p[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    sort(p, p+n);
    long long now = 0;
    long long up, down;
    up = down = p[n-1].y;
    for(int i = n-1; i>=0; i--) {
      ma[i] = up;
      mi[i] = down;
      up = max(up, p[i].y);
      down = min(down, p[i].y);
    }
    long long last = p[0].x;
    up = down = p[0].y;
    long long ans = 0;
    for(int i = 0; i<n; i++) {
      ans += 1LL * (up - down) * (p[i].x - last);
      up = max(p[i].y, up);
      down = min(p[i].y, down);
      if(ma[i] < up)
        up = ma[i];
      if(mi[i] > down)
        down = mi[i];
      last = p[i].x;
    }
    printf("%lld\n", ans);
  }
  return 0;
}