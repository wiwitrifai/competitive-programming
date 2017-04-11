#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;
int a[N], b[N];
vector< int > e[N];
int p[N];
int dist[N];
bool used[N];

int main() {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  memset(dist, -1, sizeof dist);
  queue< int > que;
  for (int i = 0; i < k; i++) {
    scanf("%d", p+i);
    p[i]--;
    if (dist[p[i]] == -1) {
      dist[p[i]] = 0;
      que.push(p[i]);
    }
  }
  for (int i = 1; i < n; i++) {
    scanf("%d %d", a+i, b+i);
    a[i]--; b[i]--;
    e[a[i]].push_back(i);
    e[b[i]].push_back(i);
  }
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int id : e[now]) {
      int u = a[id] + b[id] - now;
      if (dist[u] == -1) {
        used[id] = 1;
        dist[u] = dist[now] + 1;
        que.push(u);
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i < n; i++)
    cnt += !used[i];
  printf("%d\n", cnt);
  for (int i = 1; i < n; i++) if (!used[i]) {
    printf("%d", i);
    cnt--;
    if (cnt)
      printf(" ");
  }
  printf("\n");
  return 0;
}