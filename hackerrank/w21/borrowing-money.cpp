#include <bits/stdc++.h>

using namespace std;

const int N = 50;
int c[N];
vector< int > adj[N];
int n, m;
long long dp1[1<<18], cnt1[1<<18], dp2[1<<18], cnt2[1<<18];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++)
    scanf("%d", c+i);
  for(int i = 0; i<m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int mid = n/2;
  long long nloop = 1<<mid;
  dp1[0] = 0; cnt1[0] = 1;
  for(int i = 0; i<nloop; i++) if(cnt1[i]) {
    for(int j = 0; j<mid; j++) if((i & (1<<j)) == 0) {
      bool ok = true;
      for(int u : adj[j]) if(u < mid && (i & (1<<u))) {
        ok = false;
        break;
      }
      if(ok) {
        int nx = i | (1<<j);
        if(dp1[nx] <= dp1[i] + c[j]) {
          dp1[nx] = dp1[i] + c[j];
          cnt1[nx] = 1;
        }
      }
    }
  }
  for(int i = nloop-1; i>=0; i--) {
    for(int j = (i+1)|i; j < nloop; j = (j + 1) | i) {
      if(dp1[j] < dp1[i]) {
        dp1[j] = dp1[i];
        cnt1[j] = cnt1[i];
      }
      else if(dp1[j] == dp1[i]) {
        cnt1[j] += cnt1[i];
      }
    }
  }
  long long sum = 0, cnt = 0;
  dp2[0] = 0; cnt2[0] = 1;
  int mid2 = n-mid;
  nloop = 1 << mid2;
  for(int i = 0; i<nloop; i++) if(cnt2[i]) {
    for(int j = 0; j<mid2; j++) if((i & (1<<j)) == 0) {
      bool ok = true;
      int v = j + mid;
      for(int u : adj[v]) if(u >= mid && (i & (1<<(u-mid)))) {
        ok = false;
        break;
      }
      if(ok) { 
        int nx = i | (1<<j);
        if(dp2[nx] <= dp2[i] + c[v]) {
          dp2[nx] = dp2[i]+c[v];
          cnt2[nx] = 1;
        }
      }
    }
    int mask = (1<<mid)-1;
    for(int j = 0; j<mid2; j++) if((i & (1<<j))) {
      int v = j + mid;
      for(int u : adj[v]) if(u < mid && (mask & (1<<u)))
        mask ^= 1<<u;
    }
    // cerr << sum << " =   " << dp2[i] << " + " << dp1[mask] << " " <<  mask << " " << i << " " << cnt1[mask] * cnt2[i] << endl;
    if(sum < (dp2[i] + dp1[mask])) {
      sum = dp2[i] + dp1[mask];
      cnt = cnt1[mask];
    }
    else if(sum == (dp2[i] + dp1[mask]))
      cnt += cnt1[mask];
  }
  printf("%lld %lld\n", sum, cnt);
  return 0;
}