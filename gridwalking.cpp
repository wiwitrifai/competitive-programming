#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 11, M = 303, D = 101;

int n, m;
int x[N], d[N];
long long dp[N][M][D], ans[N][M];

long long get(int id, int move, int pos) {
  if(move == 0)
    return 0;
  if(dp[id][move][pos] != -1)
    return dp[id][move][pos];
  long long &ret = dp[id][move][pos];
  ret = 0;
  if(pos+1<=d[id])
    ret = (ret + get(id, move-1, pos+1)) % mod;
  if(pos-1> 0)
    ret = (ret + get(id, move-1, pos-1)) % mod;
  return ret;
}

long long solve()


int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++) {
      scanf("%d", x+i);
    }
    for(int i = 0; i<n; i++)
      scanf("%d", d+i);
    printf("%d\n");
  }

  return 0;
}