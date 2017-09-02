#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
pair<int, int > r[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a, s;
    scanf("%d %d", &a, &s);
    r[i] = {a, s};
  }
  sort(r, r+n);
  priority_queue<int> pq;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a = r[i].first, s = r[i].second;
    while (!pq.empty() && -pq.top() < a - m) pq.pop();
    if (!pq.empty()) {
      int top = -pq.top();
      if (top <= a && top+m >= a)
        pq.pop(), ans++;
    }
    pq.push(- a - s);
  }
  printf("%d\n", ans);
  return 0;
}