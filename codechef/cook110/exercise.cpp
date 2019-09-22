#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, inf = 1e8 + 7;

int high[N], low[N], a[N];

char s[N];
priority_queue<pair<int, int>> pq;
inline void upd_low(int v, int x) {
  if (low[v] >= x) return;
  low[v] = x;
  pq.emplace(-x, v);
}
inline void upd_high(int v, int x) {
  if (high[v] <= x) return;
  high[v] = x;
  pq.emplace(x, v);
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    if (a[i] < 0) {
      low[i] = 0;
      high[i] = inf;
    }
    else {
      low[i] = high[i] = a[i];
    }
  }
  scanf("%s", s);
  while (!pq.empty()) pq.pop();
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) continue;
    pq.emplace(-low[i], i);
  }
  while (!pq.empty()) {
    int now = pq.top().second, val = -pq.top().first;
    pq.pop();
    if (low[now] > high[now]) {
      puts("NO");
      return;
    }
    if (low[now] != val) continue;
    if (now > 0) {
      if (s[now-1] == '>') {
        upd_low(now-1, val+1);
      }
      else if (s[now-1] == '=') {
        upd_low(now-1, val);
      }
    }
    if (now < n-1) {
      if (s[now] == '<') {
        upd_low(now+1, val+1);
      }
      else if (s[now] == '=') {
        upd_low(now+1, val);
      }
    }
  }
  while (!pq.empty()) pq.pop();
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) continue;
    pq.emplace(high[i], i);
  }
  while (!pq.empty()) {
    int now = pq.top().second, val = pq.top().first;
    pq.pop();
    if (low[now] > high[now]) {
      puts("NO");
      return;
    }
    if (high[now] != val) continue;
    if (now > 0) {
      if (s[now-1] == '<') {
        upd_high(now-1, val-1);
      }
      else if (s[now-1] == '=') {
        upd_high(now-1, val);
      }
    }
    if (now < n-1) {
      if (s[now] == '>') {
        upd_high(now+1, val-1);
      }
      else if (s[now] == '=') {
        upd_high(now+1, val);
      }
    }
  }
  bool ans = 1;
  for (int i = 0; i < n; ++i)
    ans &= low[i] <= high[i];
  puts(ans ? "YES" : "NO");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
