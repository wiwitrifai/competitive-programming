#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int r[N];

bool cmp(int a, int b) {
  return r[a] > r[b];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", r+i);
  int mi = r[0], ma = r[0], sum = 0;
  for (int i = 0; i < n; i++) {
    mi = min(mi, r[i]);
    ma = max(ma, r[i]);
    sum += r[i];
  }
  int now = mi, del = sum - now * n;
  while (del - ma + now < ma - now && now >= 0) {
    now--;
    del = sum - now * n;
  }
  now = max(now, 0);
  del = 0;
  for (int i = 0; i < n; i++)
    del += r[i] - now;
  printf("%d\n", now);
  if (now == 0) {
    vector< pair<int, int > > ans;
    priority_queue< pair<int, int > > pq;
    for (int i = 0; i < n; i++) if (r[i] > now)
      pq.push(make_pair(r[i], i));
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      int v = (u == 0);
      if (!pq.empty()) {
        v = pq.top().second;
        pq.pop();
      }
      r[u]--;
      r[v]--;
      ans.emplace_back(u, v);
      if (r[u] > now)
        pq.push(make_pair(r[u], u));
      if (r[v] > now)
        pq.push(make_pair(r[v], v));
    }
    printf("%d\n", ans.size());
    for (auto it : ans) {
      int a = it.first, b = it.second;
      if (a > b)
        swap(a, b);
      for (int i = 0; i < a; i++) printf("0");
      printf("1");
      for (int i = a+1; i < b; i++) printf("0");
      printf("1");
      for (int i = b+1; i < n; i++) printf("0");
      printf("\n");
    }
  }
  else {
    vector< int > id;
    for (int i = 0; i < n; i++)
      id.push_back(i);
    sort(id.begin(), id.end(), cmp);
    vector< pair<int, int> > ans;
    if (del & 1) {
      r[id[0]]--;
      r[id[1]]--;
      r[id[2]]--;
    }
    priority_queue< pair<int, int > > pq;
    for (int i = 0; i < n; i++) if (r[i] > now)
      pq.push(make_pair(r[i], i));
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      int v = (u == 0);
      if (!pq.empty()) {
        v = pq.top().second;
        pq.pop();
      }
      r[u]--;
      r[v]--;
      ans.emplace_back(u, v);
      if (r[u] > now)
        pq.push(make_pair(r[u], u));
      if (r[v] > now)
        pq.push(make_pair(r[v], v));
    }
    printf("%d\n", ans.size() + (del & 1));
    if (del & 1) {
      sort(id.begin(), id.begin() + 3);
      for (int i = 0; i < id[0]; i++) printf("0"); printf("1");
      for (int i = id[0] + 1; i < id[1]; i++) printf("0"); printf("1");
      for (int i = id[1] + 1; i < id[2]; i++) printf("0"); printf("1");
      for (int i = id[2] + 1; i < n; i++) printf("0");
      printf("\n");
    }
    for (auto it : ans) {
      int a = it.first, b = it.second;
      if (a > b)
        swap(a, b);
      for (int i = 0; i < a; i++) printf("0");
      printf("1");
      for (int i = a+1; i < b; i++) printf("0");
      printf("1");
      for (int i = b+1; i < n; i++) printf("0");
      printf("\n");
    }
  }
  return 0;
}