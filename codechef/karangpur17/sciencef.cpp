#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1005;
const long long mod = 1e9 + 7;
const long long inf = 1e15;
 
long long d[N][N];
long long calc[16][1 << 16];
 
int p[20], t[20], m[20];
vector<pair<int, int>> edge[N];
int add[N];
long long dp[1 << 16];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}
 
long long inv(long long a) {
  return power(a, mod - 2);
}
 
int main() {
  int v, e, s, f, n;
  scanf("%d %d %d %d %d", &v, &e, &s, &f, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", p + i, t + i, m + i);
    add[p[i]] |= (1 << i);
  }
  for (int i = 0; i < e; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      d[i][j] = inf;
    }
  }
  for (int st = 1; st <= v; st++) {
    for (int i = 1; i <= v; i++) {
      d[st][i] = inf;
    }
    priority_queue<pair<long long, int>> pq;
    d[st][st] = 0;
    pq.emplace(0, st);
    while (!pq.empty()) {
      long long cost; int now;
      tie(cost, now) = pq.top();
      pq.pop();
      if (add[now] && now != st) continue;
      cost = -cost;
      if (cost != d[st][now]) continue;
      for (auto it : edge[now]) {
        int to = it.first;
        long long cur = cost + it.second;
        if (cur < d[st][to]) {
          d[st][to] = cur;
          pq.emplace(-d[st][to], to);
        }
      }
    }
  }
  priority_queue<tuple<long long, int, int>> pq;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      calc[i][j] = inf;
    }
    calc[i][1 << i] = d[s][p[i]];
    pq.emplace(-calc[i][1 << i], i, 1 << i);
  }
  while (!pq.empty()) {
    long long cost; int now, mask;
    tie(cost, now, mask) = pq.top(); pq.pop();
    cost = -cost;
    if (calc[now][mask] != cost) continue;
    for (int i = 0; i < n; ++i) {
      int nmask = mask | (1 << i);
      if (calc[i][nmask] > cost + d[p[now]][p[i]]) {
        calc[i][nmask] = cost + d[p[now]][p[i]];
        pq.emplace(-calc[i][nmask], i, nmask);
      }
    }
  }
  for (int j = 1; j < (1 << n); j++) {
    dp[j] = inf;
    for (int i = 0; i < n; i++) {
      dp[j] = min(dp[j], calc[i][j] + d[p[i]][f]);
    }
  }
  
  //puts("dijkstra done");
  for (int j = 1; j < (1 << n); j++) {
    long long talk = 1;
    for (int i = 0; i < n; i++) {
      if (j & (1 << i)) {
        talk = talk * t[i] % mod;
      }
    }
    dp[j] += talk;
  }
  //puts("dp done");
  for (int k = 0; k < n; ++k)
    for (int j = 0; j < (1 << n); j++) {
      dp[j] = min(dp[j], dp[j | (1 << k)]);
    }
  //puts("n * 2^n done");
  long long ans = 0;
  long long inv_100 = inv(power(100, n));
  //puts("cari inv done");
  for (int mask = 0; mask < (1 << n); mask++) {
    long long prob = 1;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        prob = prob * m[i] % mod;
      } else {
        prob = prob * (100 - m[i]) % mod;
      }
    }
    long long cur = dp[mask] * prob % mod * inv_100 % mod;
    ans = (ans + cur) % mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
 