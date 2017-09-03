#include <bits/stdc++.h>

using namespace std;

const int N = 8000 + 5;
const int inf = 1e8;
int cnt[121];
int x[6], y[6];
vector< int > prevs[121];
bool st[121], en[121];
int cost[N][6];
int dp[2][121];

int main() {
  for(int i = 0; i<5; i++)
    x[i] = y[i] = i;
  int a = 0;
  do {
    sort(y, y+5);
    int b = 0;
    do {
      bool ok = true;
      for(int i = 0; i<4; i++) {
        for(int j = i+1; j<4; j++)
          ok &= ((x[i] < x[j]) == (y[i+1] < y[j+1]));
      }
      if (ok)
        prevs[a].push_back(b);
      b++;
    } while(next_permutation(y, y+5));
    assert(b == 120);
    st[a] = ((x[0] + x[1]) == 7);
    en[a] = ((x[3] + x[4]) == 7);
    cnt[a] = x[2];
    a++;
  } while(next_permutation(x, x+5));
  assert(a == 120);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for(int i= 0; i<n; i++)
      for(int j = 0; j<5; j++)
        scanf("%d", cost[i] + j);
    if(n == 1) {
      printf("%d\n", cost[0][0]);
      continue;
    }
    else if(n == 2) {
      printf("%d\n", max(cost[0][0] + cost[1][1], cost[0][1] + cost[1][0]));
      continue;
    }
    for(int i = 0; i<120; i++)
      dp[0][i] = st[i] ? cost[0][cnt[i]] : -inf;
    for(int i = 1; i<n; i++) {
      int cur = i & 1, pre = cur ^ 1;
      for(int j = 0; j<120; j++) {
        dp[cur][j] = -inf;
        for(int k : prevs[j])
          dp[cur][j] = max(dp[cur][j], dp[pre][k]);
        if (dp[cur][j] > -inf)
          dp[cur][j] += cost[i][cnt[j]];
      }
    }
    int ans = -inf;
    int last = (n-1) & 1;
    for(int i = 0; i<120; i++) if(en[i])
      ans = max(ans, dp[last][i]);
    printf("%d\n", ans);
  }
  return 0;
}