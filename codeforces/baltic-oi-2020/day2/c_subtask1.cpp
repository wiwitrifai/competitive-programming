#include <bits/stdc++.h>

using namespace std;

const int N = 105, L = 55;
const long long inf = -1;

int g, n, m;
int from[N];
vector<int> mutation[N];
vector<int> anti[L];
long long ans[N], dp[N];

vector<int> rev[N];

long long maxi(long long u, long long v) {
  if (u == inf || v == inf)
    return inf;
  return max(u, v);
}

long long mini(long long u, long long v) {
  if (u == inf)
    return v;
  if (v == inf)
    return u;
  return min(u, v);
}

long long add(long long u, long long v) {
  if (u == inf || v == inf)
    return inf;
  return u + v;
}

int main() {
  scanf("%d %d %d", &g, &n, &m);
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d %d", from+i, &k);
    mutation[i].resize(k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &mutation[i][j]);
      rev[mutation[i][j]].push_back(i);
    }
  }
  for (int i = 0; i < m; ++i) {
    int l;
    scanf("%d", &l);
    anti[i].resize(l);
    for (int j = 0; j < l; ++j)
      scanf("%d", &anti[i][j]);
  }
  ans[0] = 1;
  ans[1] = 1;
  fill(ans+2, ans+g, inf);
  fill(dp, dp+n, inf);
  for (int i = 0; i < g; ++i) {
    sort(rev[i].begin(), rev[i].end());
    rev[i].erase(unique(rev[i].begin(), rev[i].end()), rev[i].end());
  }
  vector<bool> inqueue(g);
  queue<int> que;
  que.push(0);
  que.push(1);
  inqueue[0] = inqueue[1] = true;
  while (!que.empty()) {
    int v = que.front();
    inqueue[v] = false;
    que.pop();
    for (int mut : rev[v]) {
      long long res = 0;
      for (int x : mutation[mut]) {
        res = add(res, ans[x]);
      }
      dp[mut] = mini(dp[mut], res);
      int a = from[mut];
      if (ans[a] != mini(ans[a], dp[mut])) {
        ans[a] = mini(ans[a], dp[mut]);
        if (!inqueue[a]) {
          que.push(a);
          inqueue[a] = true;
        }
      }
    }
  }
  for (int i = 2; i < g; ++i) {
    if (ans[i] == inf) {
      puts("YES");
    } else {
      printf("NO %lld\n", ans[i]);
    }
  }
  return 0;
}
