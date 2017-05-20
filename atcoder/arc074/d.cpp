#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];

long long pre[N], suf[N];

int main() {
  memset(pre, -1, sizeof pre);
  memset(suf, -1, sizeof suf);
  int n;
  scanf("%d", &n);
  priority_queue< int > pq;
  long long cur = 0;
  for (int i = 0; i < 3 * n; i++) {
    scanf("%d", a+i);
    pq.push(-a[i]);
    cur += a[i];
    while (pq.size() > n) {
      int top = pq.top();
      cur += top;
      pq.pop();
    }
    if (pq.size() == n) {
      pre[i] = cur;
    }
  }
  while (!pq.empty()) pq.pop();
  cur = 0;
  for (int i = 3 * n-1; i >= 0; i--) {
    cur += a[i];
    pq.push(a[i]);
    while (pq.size() > n) {
      int top = pq.top();
      cur -= top;
      pq.pop();
    }
    if (pq.size() == n) {
      suf[i] = cur;
    }
  }
  long long ans = -1e18;
  for (int i = 0; i < 3 * n; i++) {
    if (pre[i] == -1 || suf[i+1] == -1) continue;
    if (ans < pre[i] - suf[i+1])
      ans = pre[i] - suf[i+1];
  }
  printf("%lld\n", ans);
  return 0;
}