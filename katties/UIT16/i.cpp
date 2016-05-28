#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m, s, t;
vector< int > adj[N];
long long dp[N][N];

int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  while(m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dp[s][0] = 1;
  set< pair<int, int> > st;
  st.insert(make_pair(0, s));
  int now = 0;
  long long ans = 0;
  while(!st.empty()) {
    auto it = st.begin();
    int tmp = it->first, v = it->second;
    // cout << tmp << " " << v << endl;
    st.erase(it);
    if(tmp == t) {
      ans += dp[v][tmp];
      continue;
    }
    for(int i = 0; i<adj[v].size(); i++) {
      st.insert(make_pair(tmp+1, adj[v][i]));
      dp[adj[v][i]][tmp+1] += dp[v][tmp];
    }
  }
  cout << ans << endl;
  return 0;
}