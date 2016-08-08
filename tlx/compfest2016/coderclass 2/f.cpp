#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int t, n, k, a[N], cnt[N];

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n; i++)
      scanf("%d", a+i);
    long long ans = 0;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i<k; i++) if(a[i] < N) {
      cnt[a[i]]++;
      if(cnt[a[i]] == a[i])
        ans++;
      else if(cnt[a[i]] == a[i]+1)
        ans--;
    }
    int tmp = ans;
    for(int i = k; i<n; i++) {
      if(a[i] < N) {
        cnt[a[i]]++;
        if(cnt[a[i]] == a[i])
          tmp++;
        else
          if(cnt[a[i]] == a[i]+1)
            tmp--;
      }
    // cerr << "cuk " << endl;
      int now = a[i-k];
      if(now < N) {
        cnt[now]--;
        if(cnt[now] == now)
          tmp++;
        else if(cnt[now] == now-1)
          tmp--;
      }
      ans += tmp;
    }
    printf("%lld\n", ans);
  }

  return 0;
}