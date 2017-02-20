#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const double eps = 1e-7;

double dp[2][N];
vector< pair< int, int > > que;
int ans[N];

int main() {
  dp[0][0] = 1;
  for (int i = 1; i < N; i++)
    dp[0][i] = 0;
  int k, q;
  scanf("%d %d", &k , &q);
  for (int i = 0; i < q; i++) {
    int p;
    scanf("%d", &p);
    que.emplace_back(p, i);
  }
  sort(que.begin(), que.end());
  int j = 0;
  for (int c = 1, now = 1; j < que.size(); c ^= 1, now++) {
    int b = c ^ 1;
    for (int i = 1; i <= k; i++) {
      dp[c][i] = (dp[b][i] * i + dp[b][i-1] * (k-i+1)) / k;
    }
    dp[c][0] = 0;
    while (j < que.size() && dp[c][k] * 2000.0 + eps >= que[j].first) ans[que[j].second] = now, j++;
  } 
  for (int i = 0; i < que.size(); i++)
    printf("%d\n", ans[i]);
  return 0;
}