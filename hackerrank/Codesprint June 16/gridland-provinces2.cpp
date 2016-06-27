#include <bits/stdc++.h>

using namespace std;

const int N = 666;
const int mod = int(1e9 + 7);
const long long p = 29;
int n;
char s[2][N];
long long h[2][N], g[2][N];
long long v[2][N];
long long pp[N*2];

int main() {
  pp[0] = 1;
  for(int j = 1; j<N; j++)
    pp[j] = (pp[j-1] * p) % mod; 
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    scanf("%s%s", s[0], s[1]);
    for(int i = 0; i<2; i++)
      for(int j = 0; j<n; j++)
        v[i][j] = s[i][j] - 'a';
    h[0][n-1] = (v[0][n-1] * p + v[1][n-1]) % mod;
    h[1][n-1] = (v[1][n-1] * p + v[0][n-1]) % mod;
    for(int j = n-2; j>=0; j--) {
      h[0][j] = (v[0][j] * pp[(n-1-j) * 2 + 1] + h[0][j+1] * p + v[1][j]) % mod;
      h[1][j] = (v[1][j] * pp[(n-1-j) * 2 + 1] + h[1][j+1] * p + v[0][j]) % mod;
    }
    g[0][0] = (v[0][0] * p + v[1][0]) % mod;
    g[1][0] = (v[1][0] * p + v[0][0]) % mod;
    for(int j = 1; j<n; j++) {
      g[0][j] = (v[0][j] * pp[j * 2 + 1] + g[0][j-1] * p + v[1][j]) % mod;
      g[1][j] = (v[1][j] * pp[j * 2 + 1] + g[1][j-1] * p + v[0][j]) % mod;
    }
    set< long long > st;
    st.clear();
    st.insert(g[0][n-1]);
    st.insert(g[1][n-1]);
    st.insert(h[0][0]);
    st.insert(h[1][0]);

    for(int i = 0; i<n; i++) {
      long long now[2], back[2];
      memset(now, 0, sizeof now);
      memset(back, 0, sizeof back);
      for(int j = i+1; j<n; j++) {
        long long cur1 = (g[0][i] + back[0] * pp[(i+1)*2] + h[(j-i)&1][j] * pp[j * 2]) % mod;
        if(cur1 < 0) cur1 += mod;
    
        st.insert(cur1);
        
        cur1 = (g[0][i] * pp[(n-1-i) * 2] + now[1] * pp[(n-j)*2] + h[(j-i)&1][j]) % mod;
        if(cur1 < 0) cur1 += mod;
        
        st.insert(cur1);

        cur1 = (g[1][i] + back[1] * pp[(i+1)*2] + h[((j-i)&1)^1][j] * pp[j * 2]) % mod;
        if(cur1 < 0) cur1 += mod;
        st.insert(cur1);
        
        cur1 = (g[1][i] * pp[(n-1-i) * 2] + now[0] * pp[(n-j)*2] + h[((j-i)&1)^1][j]) % mod;
        if(cur1 < 0) cur1 += mod;
        st.insert(cur1);
        now[0] = (now[0] * pp[2] + (((j-i)&1) ? ((v[0][j] * p + v[1][j]) % mod) : ((v[1][j] * p + v[0][j]) % mod))) % mod;
        now[1] = (now[1] * pp[2] + (((j-i)&1) ? ((v[1][j] * p + v[0][j]) % mod) : ((v[0][j] * p + v[1][j]) % mod))) % mod;

        back[0] = (back[0] + pp[(j-i-1)*2] * (!((j-i)&1) ? ((v[0][j] * p + v[1][j]) % mod) : ((v[1][j] * p + v[0][j]) % mod))) % mod;
        back[1] = (back[1] + pp[(j-i-1)*2] * (!((j-i)&1) ? ((v[1][j] * p + v[0][j]) % mod) : ((v[0][j] * p + v[1][j]) % mod))) % mod;
      }
    }
    cout << st.size() << endl;
  }
  return 0;
}