#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int a[N], b[N];

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i)
    pq.push(abs(a[i]-b[i]));
  x += y;
  while (x > 0 && !pq.empty()) {
    --x;
    int s = pq.top();
    pq.pop();
    pq.push(abs(s-1));
  }
  long long ans = 0;
  while (!pq.empty()) {
    int s = pq.top(); pq.pop();
    ans += 1LL * s * s;
  }
  cout << ans << endl;
  return 0;
}