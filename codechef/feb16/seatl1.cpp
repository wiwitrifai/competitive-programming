#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
vector< vector<int > > mat;
map< int, int > r[N], c[N];
int n, m;

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%d%d", &n, &m);
    mat.assign(n+2, vector<int>(m+2));
    set<int> s;
    int ans = 0;
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++) {
        int x;
        scanf("%d", &x);
        mat[i][j] = x;
        r[x].clear();
        c[x].clear();
        s.insert(x);
      }
    for(int i = 0; i<n; i++)
      for(int j = 0; j<m; j++) {
        r[mat[i][j]][i]++;
        c[mat[i][j]][j]++;
      }
    for(auto x : s) {
      int var, val;
      val = var = 0;
      vector< int > idr, idl;
      for(auto it : r[x]) {
        if(var < it.second) {
          var = it.second;
          idr.clear();
          idr.push_back(it.first);
        }
        else if(var == it.second)
          idr.push_back(it.first);
      }
      for(auto it : c[x]) {
        if(val < it.second) {
          val = it.second;
          idl.clear();
          idl.push_back(it.first);
        }
        else if(val == it.second)
          idl.push_back(it.first);
      }
      bool ok = true;
      for(int i = 0; i<idl.size() && ok; i++) {
        for(int j = 0; j<idr.size() && ok; j++) {
          if((mat[idr[j]][idl[i]] == x))
            ans = max(ans, val+var-1);
          else {
            ans = max(ans, val+var);
            ok = false;
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}