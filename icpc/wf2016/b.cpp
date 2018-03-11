// by luqman
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 2e9;
const long long INF = 1e18;

int d[N], rd[N];
vector<pair<int, int>> edge[N], redge[N];
long long val[N];
long long dp[N], bef[N], sum[N];
bool in[N];

long long find(int l, int r) {
  return sum[r] - (l == 0? 0 : sum[l-1]);
}

void dijkstra(int start, vector<pair<int, int>> edge[N], int dist[N]) {
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < N; i++) dist[i] = inf;
  dist[start] = 0;
  pq.emplace(0, start);
  while (!pq.empty()) {
    int cost, now;
    tie(cost, now) = pq.top();
    cost = -cost;
    pq.pop();
    if (dist[now] != cost) continue;
    for (auto it : edge[now]) {
      int near = it.first;
      int ncos = cost + it.second;
      if (dist[near] > ncos) {
        dist[near] = ncos;
        pq.emplace(-dist[near], near);
      }
    }
  }
}

void solve(int l, int r, int fl, int fr) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  dp[mid] = INF;
  int til = min(mid - 1, fr);
  int at = -1;
  for (int i = fl; i <= til; i++) {
    long long cur = bef[i] + (mid - i - 1) * find(i + 1, mid);
    if (cur < dp[mid]) {
      dp[mid] = cur;
      at = i;
    }
  }
  if (l == r) return;
  solve(l, mid - 1, fl, at);
  solve(mid + 1, r, at, fr);
}

int main() {
  int n, b, s, r;
  scanf("%d %d %d %d", &n, &b, &s, &r);
  for (int i = 0; i < r; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    edge[u].emplace_back(v, c);
    redge[v].emplace_back(u, c);
  }
  dijkstra(b + 1, edge, d);
  dijkstra(b + 1, redge, rd);
  for (int i = 1; i <= b; i++) {
    val[i] = d[i] + rd[i];
    //printf("niki %d %lld\n", i, val[i]);
  }
  sort(val + 1, val + 1 + b);
  for (int i = 1; i <= b; i++) {
    sum[i] = sum[i - 1] + val[i];
    //printf("val %lld\n", val[i]);
  }
  for (int i = 0; i < N; i++) dp[i] = bef[i] = INF;
  bef[0] = 0;
  for (int i = 0; i < s; i++) {
    solve(1, b, 0, b - 1);
    for (int j = 0; j < N; j++) bef[j] = dp[j];
  }
  cout << dp[b] << endl;
  return 0;
}