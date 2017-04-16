#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int fp[N], haram[N], ish[N];
int cnt[N];
int dp[N], to[N];
int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}
vector< int > vk[N];
void extendedEuclidean(long long a, long long b, long long &x, long long &y, long long &d) {
  if(b == 0) { x = 1; y = 0; d = a; return; } 
  extendedEuclidean(b, a % b, x, y, d); 
  long long xx, yy;
  xx = y;
  yy = x - (a/b)*y;
  x = xx; y = yy;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", haram+i);
    if (haram[i] == 0)
      haram[i] = m;
    ish[haram[i]] = 1;
  }
  int k = 0;
  for (int i = 1; i <= m; i++) {
    if (m % i) continue;
    fp[k] = i;
    k++;
  }
  for (int i = 1; i <= m; i++) {
    if (ish[i]) continue;
    int d = gcd(i, m);
    int id = lower_bound(fp, fp+k, d) - fp;
    vk[id].push_back(i);
  }
  for (int i = 0; i < k; i++)
    dp[i] = vk[i].size(), to[i] = -1;
  for (int i = k-1; i >= 0; i--) {
    for (int j = i+1; j < k; j++) if ((fp[j] % fp[i]) == 0) {
      if (dp[i] < dp[j] + vk[i].size()) {
        dp[i] = dp[j] + vk[i].size();
        to[i] = j;
      }
    }
  }
  vector< int > pre;
  int now = 0;
  while (now >= 0) {
    for (int v : vk[now])
      pre.push_back(v);
    now = to[now];
  }
  printf("%d\n", pre.size());
  if (pre.size()) {
    printf("%d", pre[0] % m);
    for (int i = 1; i < pre.size(); i++) {
      int cur = pre[i-1];
      long long x, y, d;
      extendedEuclidean(cur, m, x, y, d);
      x %= m;
      if (x < 0) x += m;
      x = (x * (pre[i]/d)) % m;
      if (x < 0) x += m;
      printf(" %d", (int)x);
    }
    printf("\n");
  }
  return 0;
}