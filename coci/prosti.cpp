#include <bits/stdc++.h>

using namespace std;

const int N = 160;
bool isprim[N];
int cnt[N], val[N];
set< pair<int, int > > s[N][N];

int solve(int k, int l, int m) {
  m--;
  auto it = s[m][k].lower_bound({l, 0});
  if(it == s[m][k].end())
    return -1;
  return it->second + 1;
}

int main() {
  memset(isprim, true, sizeof isprim);
  isprim[0] = isprim[1] = false;
  for(int i = 2; i<N; i++) {
    if(isprim[i]) {
      for(int j = i*i; j<N; j+= i)
        isprim[j] = false;
    }
    cnt[i] = cnt[i-1] + isprim[i];
  }
  memset(val, -1, sizeof val);
  for(int m = 1; m<N; m++) {
    for(int k = 1; k<=m; k++) {
      val[0] = m+1; 
      int now = cnt[k];
      for(int i = 1; i<=m; i++) {
        if(val[now] == -1)
          val[now] = i;
        if(isprim[i])
          now--;
        if(i+k <= m && isprim[i+k])
          now++;
      }
      for(int i = 0; i<= k; i++)
        if(val[i] != -1) {
          s[m][k].insert({i, val[i]});
          val[i] = -1;
        }
    }
  }

  int q;
  scanf("%d", &q);
  while(q--) {
    int k, l, m;
    scanf("%d%d%d", &k, &l, &m);
    printf("%d\n", solve(k, l, m));
  }
  return 0;
}