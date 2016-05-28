#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > adj[N];

int cnt[3][N], a[3][N];

bool dead[N], used[N];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<3; i++)
    for(int j = 0; j<n; j++) {
      scanf("%d", a[i]+j);
      a[i][j]--;
      cnt[i][a[i][j]]++;
      adj[a[i][j]].push_back(j);
    }
  for(int i = 0; i<n; i++) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
  }
  memset(dead, 0, sizeof dead);
  memset(used, 0, sizeof used);
  for(int i = 0; i<n; i++) if(!dead[i]) {
    if(cnt[0][i] == 0 || cnt[1][i] == 0 || cnt[2][i] == 0) {
      queue< int > q;
      q.push(i);
      dead[i] = true;
      while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int j : adj[v]) if(!used[j]) {
          used[j] = 1;
          for(int k = 0; k<3; k++) {
            cnt[k][a[k][j]]--;
            if(cnt[k][a[k][j]] == 0 && !dead[a[k][j]]) {
              dead[a[k][j]] = true;
              q.push(a[k][j]); 
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i<n; i++) {
    // if(used[i])
    // cout << i << " ha\n";
    ans+= used[i];
  }
  printf("%d\n", ans);
  return 0;
}