#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const long long inf = 1e15;

long long dp[N][N];
int x[N], p[N], c[N];
pair< int, int > pc[N];
long long tmp[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", x+i);
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", p+i, c+i);
    sum += c[i]; 
    pc[i] = {p[i], c[i]};
  }
  if (sum < n) {
    puts("-1");
    return 0;
  }
  sort(x, x+n);
  sort(pc, pc+m);
  for (int i = 0; i < m; i++)
    p[i] = pc[i].first, c[i] = pc[i].second;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    deque< long long > dq;
    long long off = 0;
    for (int j = 0; j <= n; j++) {
      while (!dq.empty()) {
        if (dq.front() + off > dp[i][j])
          dq.pop_front();
        else
          break;
      }
      dq.push_front(dp[i][j]-off);
      tmp[j] = dp[i][j]-off;
      dp[i+1][j] = min(dp[i+1][j], dq.back()+off);
      if (j < n) {
        if (j >= c[i] && dq.back() == tmp[j-c[i]])
          dq.pop_back();
        off += abs(x[j]-p[i]);
      }
      // cerr << i << " " << j << " " << dp[i][j] << endl; 
    }
  }
  if (dp[m][n] >= inf)
    dp[m][n] = -1;
  cout << dp[m][n] << endl;
  return 0;
}