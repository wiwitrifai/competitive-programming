#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n;
vector< int > a;
vector< int > adj[N];
int dp[N], in[N];

int main() {
  scanf("%d", &n);
  int cnt = 0;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    if(x)
      a.push_back(x);
    else
      cnt++;
  }
  if(cnt)
    a.push_back(0);
  sort(a.begin(), a.end());
  int ans = max(2, cnt);;
  for(int i = 0; i<a.size(); i++) {
    for(int j = i+1; j<a.size(); j++) {
      if(a[i] != 0 && a[j] != 0) {
        int v = a.size() * i, u = a.size() * j;
        int l = upper_bound(a.begin(), a.end(), a[i]+a[j]-1)-a.begin(),
            r = upper_bound(a.begin(), a.end(), a[i]+a[j]) - a.begin();
        if(a[i] + a[j] == 0)
          cout <<l << " cuk " << r << endl;
        for(int z = l; z < r; z++) {
          if(u+z == 1 || v+z == 1)
            cout << i << " heh " << j << endl;
          adj[v+j].push_back(u+z);
          in[u+z]++; 
          adj[u+i].push_back(v+z);
          in[v+z]++;
        }
        if(a[i] == a[j] && cnt > 0) {
            l = upper_bound(a.begin(), a.end(), a[i]-1)-a.begin();
            r = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
            int o = lower_bound(a.begin(), a.end(), 0) - a.begin();
          for(int z = l; z<r; z++) if(z != i && z != j) {
            adj[l*a.size() + o].push_back(v+j);
            in[v+j]++;
            adj[l*a.size() + o].push_back(u+i);
            in[u+i]++;
          }
        } 
      }
    }
  }
  int n = a.size()*a.size();
  stack< int > st;
  for(int i = 0; i<n; i++) {
    if(in[i] == 0)
      st.push(i);
  }
  cout << a.size() << endl;
  int o = lower_bound(a.begin(), a.end(), 0) - a.begin();
  while(!st.empty()) {
    int v = st.top(); st.pop();
    bool zero = (cnt > 0) && ((v-o) % a.size() == 0);
    if(v == 1)
    cout << v << " " << dp[v] << endl;
    for(int u : adj[v]) {
      in[u]--;
      // if((cnt > 0) && ((u-o) % a.size() == 0))
      if(u == 1)
        cout << u << " " << v << " " << dp[u] << endl;
      if(zero)
        dp[u] = max(dp[u], dp[v]+2);
      else
        dp[u] = max(dp[u], dp[v]+1);
      if(in[u] == 0)
        st.push(u);
    }
  }
  for(int i = 0; i<n; i++)
    ans = max(ans, dp[i]+2);
  cout << ans << endl;
  return 0;
}