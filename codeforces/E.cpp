#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> mp[32];
set<pair<int, int>> s;

main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < 32; i++) mp[i].clear();
    int n, m;
    scanf("%d %d", &n, &m);
    s.clear();
    for(int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      for(int j = 0; j <= 30; j++) {
        int at = (a & ~((1 << j) - 1));
        mp[j][at].push_back(i);
        //printf("%d masuk %d %d\n", a, j, at);
        s.insert(make_pair(j, at));
      }
    }
    for(auto it : s) {
      int a = it.first;
      int b = it.second;
      sort(mp[a][b].begin(), mp[a][b].end());
    }
    while(m--) {
      int v;
      scanf("%d", &v);
      int now = 0;
      for(int i = 30; i >= 0; i--) {
        int c = (now | ((1 << i) & v));
        int b = (c ^ (1 << i));
        if(mp[i].count(b) && !mp[i][b].empty()) {
          now = b;
        } else {
          now = c;
        }
        //printf("now %d\n", now);
        if(mp[i][now].size() == 1) {
          printf("%d\n", mp[i][now][0]);
          goto DONE;
        }
        while(mp[i][now].empty());
      }

      printf("%d\n", mp[0][now][0]);
      DONE:;
    }
  }
  
  return 0;
}