#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<long long> pq;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    pq.push(-x);
  }
  if ((pq.size() & 1) == 0)
    pq.push(0);
  while (pq.size() > 2) {
    long long now = -pq.top();
    pq.pop();
    now += -pq.top();
    pq.pop();
    now += -pq.top();
    pq.pop();
    ans += now;
    pq.push(-now);
  }
  cout << ans << endl;
  return 0;
}