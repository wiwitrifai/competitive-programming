#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<pair<int, pair<int, int> > > adj[N];
int n, m, q, l, r, val, color[N];

bool check() {
  for(int i = 0; i<n; i++)
    color[i] = -1;
  bool isbi = true;
  for(int i = 0; i<n; i++) if(color[i] == -1) {
    queue<int > que;
    while(!que.empty())
      que.pop();
    que.push(i);
    color[i] = 0;
    while(!que.empty()) {
      int u = que.front();
      que.pop();
      for(auto it : adj[u]) if(it.second.first > val && it.second.second <= r && it.second.second >= l) {
        int v = it.first;
        if(color[v] == -1) {
          color[v] = 1 ^ color[u];
          que.push(v);
        }
        else if(color[v] == color[u]) {
          isbi = false;
          break;
        }
      }
    }
    if(!isbi)
      break;
  }
  return isbi;
}

int main() {
  vector< int > vals;
  scanf("%d%d%d", &n,&m, &q);
  for(int i = 0; i<m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--; v--;
    adj[u].push_back({v, {w, i}});
    adj[v].push_back({u, {w, i}});
    vals.push_back(w);
  }
  vals.push_back(-1);
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  while(q--) {
    scanf("%d%d", &l, &r);
    l--; r--;
    // cerr << l << " " << r << endl;
    int lo = 0, hi = (int)vals.size()-1;
    while(lo < hi) {
      int mid = (lo + hi)>>1;
      val = vals[mid];
      bool res = check();
      // cerr << val << " | " << res << endl;
      if(res)
        hi = mid;
      else
        lo = mid+1;
    }
    printf("%d\n", vals[lo]);
  }
  return 0;
}