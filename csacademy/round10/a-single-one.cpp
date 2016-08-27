#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e8;

int a[N];
bool vis[N];

int main() {
  int n, m, k, s;
  scanf("%d %d %d %d", &n, &k, &m, &s);
  for (int i = 0; i < n; i++)
    a[i] = inf;
  a[--s] = 0;
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    a[x-1] = -1;
  }
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    int next = now-k, prev = now + k, lo, hi;
    int ma = min(now, n-k);
    lo = -1;
    hi = n;
    for (int i = max(0, now - k + 1); i <= ma; i++) {
      int to = i + k - 1 - (now - i);
      if (a[to] > a[now] + 1) {
        a[to] = a[now] + 1;
        if (to-k< 0 || to+k >=n) {
          if (to-k < 0) {
            lo = max(lo, to);
          }
          if (to+k >= n)
            hi = min(hi, to);
        }
        else {
          next = max(next, to);
          prev = min(prev, to);
        }
      }
    }
    if (lo >= 0 && !vis[lo]) {
      q.push(lo);
      vis[lo] = 1;
    }
    if (hi < n && !vis[hi]) {
      q.push(hi);
      vis[hi] = 1;
    }
    if (next > now - k && !vis[next]) {
      q.push(next);
      vis[next] = 1;
    }
    if (prev < now + k && !vis[prev]) {
      q.push(prev);
      vis[prev] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= inf)
      a[i] = -1;
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}