#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1 << 9;

int fav[N];
int cost[N], ing[N];

int read_mask() {
  int c;
  scanf("%d", &c);
  int mask = 0;
  for (int i = 0; i < c; ++i) {
    int x;
    scanf("%d", &x);
    mask |= 1 << (x-1);
  }
  return mask;
}

int sel[M], cnt[M], sum[M];

pair<int, int> best[M];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    fav[i] = read_mask();
    ++cnt[fav[i]];
  }
  vector<int> prio(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", cost+i);
    ing[i] = read_mask();
    prio[i] = i;
  }
  sort(prio.begin(), prio.end(), [](int le, int ri) {
    return cost[le] < cost[ri];
  });
  for (int i = 0; i < M; ++i) {
    sel[i] = -1;
    best[i] = {-1, -1};
  }
  for (int p : prio) {
    int cur = ing[p];
    if (sel[cur] == -1) {
      sel[cur] = p;
      best[cur].first = p;
    }
    else if (best[cur].second == -1) {
      best[cur].second = p;
    }
  }
  for (int i = 0; i < M; ++i) {
    if (sel[i] == -1) continue;
    for (int j = i+1; j < M; ++j) {
      if (sel[j] == -1) continue;
      int tot = cost[sel[i]] + cost[sel[j]];
      int uni = i|j;
      if (best[uni].second == -1 || tot < cost[best[uni].first] + cost[best[uni].second]) {
        best[uni] = {sel[i], sel[j]};
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      if ((i & j) != j) continue;
      sum[i] += cnt[j];
    }
  }
  pair<int, int> ans = {0, 1};
  int ans_cnt = -1, ans_cost = 0;
  for (int i = 0; i < M; ++i) {
    if (best[i].second == -1) continue;
    if (ans_cnt > sum[i]) continue;
    int cur_cost = cost[best[i].first] + cost[best[i].second];
    if (ans_cnt == sum[i] && cur_cost >= ans_cost) continue;
    ans = best[i];
    ans_cnt = sum[i];
    ans_cost = cur_cost;
  }
  if (ans.first > ans.second)
    swap(ans.first, ans.second);
  printf("%d %d\n", ans.first + 1, ans.second + 1);
  return 0;
}
