#include <bits/stdc++.h>

using namespace std;

const int N = 666;
const int mod[] = {int(1e9 + 7), int(1e9 + 9)};
const long long p[] = {29, 37};
int n;
char s[2][N];
long long h[2][2][N], g[2][2][N];
long long v[2][N];
long long pp[2][N*4];
vector< pair<long long, long long> > hh;

int main() {
  for(int i = 0; i<2; i++) {
    pp[i][0] = 1;
    for(int j = 1; j<N*4; j++)
      pp[i][j] = (pp[i][j-1] * p[i]) % mod[i]; 
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    scanf("%s%s", s[0], s[1]);
    for(int i = 0; i<2; i++)
      for(int j = 0; j<n; j++)
        v[i][j] = s[i][j] - 'a';
    for(int i = 0; i<2; i++) {
      h[i][0][n-1] = (v[0][n-1] * p[i] + v[1][n-1]) % mod[i];
      h[i][1][n-1] = (v[1][n-1] * p[i] + v[0][n-1]) % mod[i];
      for(int j = n-2; j>=0; j--) {
        h[i][0][j] = (v[0][j] * pp[i][(n-1-j) * 2 + 1] + h[i][0][j+1] * p[i] + v[1][j]) % mod[i];
        h[i][1][j] = (v[1][j] * pp[i][(n-1-j) * 2 + 1] + h[i][1][j+1] * p[i] + v[0][j]) % mod[i];
      }
    }
    for(int i = 0; i<2; i++) {
      g[i][0][0] = (v[0][0] * p[i] + v[1][0]) % mod[i];
      g[i][1][0] = (v[1][0] * p[i] + v[0][0]) % mod[i];
      for(int j = 1; j<n; j++) {
        g[i][0][j] = (v[0][j] * pp[i][j * 2 + 1] + g[i][0][j-1] * p[i] + v[1][j]) % mod[i];
        g[i][1][j] = (v[1][j] * pp[i][j * 2 + 1] + g[i][1][j-1] * p[i] + v[0][j]) % mod[i];
      }
    }
    hh.clear();
    hh.push_back({g[0][0][n-1], g[1][0][n-1]});
    hh.push_back({g[0][1][n-1], g[1][1][n-1]});
    hh.push_back({h[0][0][0], h[1][0][0]});
    hh.push_back({h[0][1][0], h[1][1][0]});

    for(int i = 0; i<n; i++) {
      long long now[2][2], back[2][2];
      memset(now, 0, sizeof now);
      memset(back, 0, sizeof back);
      for(int j = i+1; j<n; j++) {
        long long cur1 = (g[0][0][i] + back[0][0] * pp[0][(i+1)*2] + h[0][(j-i)&1][j] * pp[0][j * 2]) % mod[0];
        long long cur2 = (g[1][0][i] + back[1][0] * pp[1][(i+1)*2] + h[1][(j-i)&1][j] * pp[1][j * 2]) % mod[1];
        if(cur1 < 0) cur1 += mod[0];
        if(cur2 < 0) cur2 += mod[1];
    
        hh.push_back({cur1, cur2});
        
        cur1 = (g[0][0][i] * pp[0][(n-1-i) * 2] + now[0][1] * pp[0][(n-j)*2] + h[0][(j-i)&1][j]) % mod[0];
        cur2 = (g[1][0][i] * pp[1][(n-1-i) * 2] + now[1][1] * pp[1][(n-j)*2] + h[1][(j-i)&1][j]) % mod[1];
        if(cur1 < 0) cur1 += mod[0];
        if(cur2 < 0) cur2 += mod[1];
        hh.push_back({cur1, cur2});

        cur1 = (g[0][1][i] + back[0][1] * pp[0][(i+1)*2] + h[0][((j-i)&1)^1][j] * pp[0][j * 2]) % mod[0];
        cur2 = (g[1][1][i] + back[1][1] * pp[1][(i+1)*2] + h[1][((j-i)&1)^1][j] * pp[1][j * 2]) % mod[1];
        if(cur1 < 0) cur1 += mod[0];
        if(cur2 < 0) cur2 += mod[1];
        hh.push_back({cur1, cur2});
        
        cur1 = (g[0][1][i] * pp[0][(n-1-i) * 2] + now[0][0] * pp[0][(n-j)*2] + h[0][((j-i)&1)^1][j]) % mod[0];
        cur2 = (g[1][1][i] * pp[1][(n-1-i) * 2] + now[1][0] * pp[1][(n-j)*2] + h[1][((j-i)&1)^1][j]) % mod[1];
        if(cur1 < 0) cur1 += mod[0];
        if(cur2 < 0) cur2 += mod[1];
        hh.push_back({cur1, cur2});
        for(int k = 0; k<2; k++) {
          now[k][0] = (now[k][0] * pp[k][2] + (((j-i)&1)? ((v[0][j] * p[k] + v[1][j]) % mod[k]) : ((v[1][j] * p[k] + v[0][j]) % mod[k]))) % mod[k];
          now[k][1] = (now[k][1] * pp[k][2] + (((j-i)&1) ? ((v[1][j] * p[k] + v[0][j]) % mod[k]) : ((v[0][j] * p[k] + v[1][j]) % mod[k]))) % mod[k];

          back[k][0] = (back[k][0] + pp[k][(j-i-1)*2] * (!((j-i)&1) ? ((v[0][j] * p[k] + v[1][j]) % mod[k]) : ((v[1][j] * p[k] + v[0][j]) % mod[k]))) % mod[k];
          back[k][1] = (back[k][1] + pp[k][(j-i-1)*2] * (!((j-i)&1) ? ((v[1][j] * p[k] + v[0][j]) % mod[k]) : ((v[0][j] * p[k] + v[1][j]) % mod[k]))) % mod[k];
        }
      }
    }
    sort(hh.begin(), hh.end());
    if(!hh.empty())
      assert(hh[0].first >=0 && hh[0].second >= 0);
    hh.erase(unique(hh.begin(), hh.end()), hh.end());
    cout << hh.size() << endl;
  }
  return 0;
}