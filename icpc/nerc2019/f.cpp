#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, ka, kb;
  scanf("%d %d %d %d", &n, &m, &ka, &kb);
  vector<int> a(ka), b(kb);
  for (int i = 0; i < ka; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < kb; ++i)
    scanf("%d", &b[i]);
  int edge = n + m - 1;
  if (ka + n > edge || kb + m > edge) {
    puts("No");
    return 0;
  }
  while ((int)a.size() + n < edge) {
    a.push_back(1);
  }
  while ((int)b.size() + m < edge) {
    b.push_back(n + 1);
  }
  vector<int> deg(n + m + 1, 1);
  for (int x : a) {
    ++deg[x];
  }
  for (int x : b) {
    ++deg[x];
  }
  priority_queue<int> pq;
  for (int i = 1; i <= n + m; ++i) {
    if (deg[i] == 1) {
      pq.push(-i);
    }
  }
  vector<pair<int, int> > ans;
  int ia = 0, ib = 0;
  for (int i = 0; i < n + m - 2; ++i) {
    int v = -pq.top();
    pq.pop();
    int u = -1;
    if (v <= n) {
      assert(ib < (int)b.size());
      u = b[ib++];
      ans.emplace_back(v, u);
    }
    else {
      assert(ia < (int)a.size());
      u = a[ia++];
      ans.emplace_back(u, v);
    }
    --deg[u];
    if (deg[u] == 1) {
      pq.push(-u);
    }
  }
  int u = -pq.top(); pq.pop();
  int v = -pq.top();
  ans.emplace_back(u, v);
  printf("Yes\n");
  for (auto e : ans) {
    printf("%d %d\n",  e.first, e.second);
  }
  return 0;
}
