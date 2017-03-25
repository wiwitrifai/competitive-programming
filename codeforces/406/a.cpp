#include <bits/stdc++.h>

using namespace std;

const int N = 7070;

int dp[2][N];
bool changed[2][N];
int n, k[2], cnt[2][N];
vector< int > st[2];

int main() {
  // time_t startt = clock();
  scanf("%d", &n);
  for (int i = 0; i < 2; i++) {
    scanf("%d", k+i);
    for (int j = 0; j < k[i]; j++) {
      int x;
      scanf("%d", &x);
      st[i].push_back(x);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cnt[i][j] = k[i];
    }
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = dp[1][0] = 0;
  queue< pair< int, int > > que;
  que.push(make_pair(0, 0));
  que.push(make_pair(1, 0));
  while (!que.empty()) {
    int p = que.front().first, v = que.front().second, q = p ^1;
    que.pop();
    if (dp[p][v] == 0) {
      for (int val : st[q]) {
        int now = (v+n-val) % n;
        if (dp[q][now] == -1)
          que.push(make_pair(q, now));
        dp[q][now] = 1;
      }
    }
    else {
      for (int val : st[q]) {
        int now = (v+n-val) % n;
        cnt[q][now]--;
        if (cnt[q][now] <= 0 && dp[q][now] == -1) {
          que.push(make_pair(q, now));
          dp[q][now] = 0;
        }
      }
    }
  }
  for (int p = 0; p < 2; p++) {
    for (int j = 1; j < n; j++)
      if (dp[p][j] == -1)
        printf("Loop ");
      else
        printf("%s ", dp[p][j] ? "Win" : "Lose");
      printf("\n");
  }
  // cerr << (double)(clock()-startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  return 0;
}