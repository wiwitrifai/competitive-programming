#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k, a[N];
int visit[N];

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  long long ans = 0;
  for(int i = 0; i<n; i++) if(!visit[i]) {
      int l = -10005, r = 10005, cnt = 0, up, btm;
      while(l < r) {
        int mid = (l+r) >> 1;
        int now = i;
        up = btm = 0;
        while(visit[now] == cnt) {
          if(mid < a[now])
            up++;
          else
            btm++;
          visit[now] = cnt+1;
          now = (now + k) % n;
        }
        cnt++;
        if(up <= btm)
          r = mid;
        else
          l = mid+1;
      }
      int now = i;
      while(visit[now] == cnt) {
        ans += abs(a[now] - l);
        visit[now] = cnt+1;
        now = (now + k) % n;
      }
  }
  printf("%lld\n", ans);
  return 0;
}
