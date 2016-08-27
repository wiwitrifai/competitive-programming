#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e17;
const int N = 2e7 + 7;
long long d[N];
bool inside[N];

int main() {
  int n;
  long long x, y;
  cin >> n >> x >> y;
  for (int i = 0; i <= 2 * n; i++)
    d[i] = inf;
  queue < int > q;
  d[0] = 0; 
  q.push(0);
  inside[0] = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    inside[now] = 0;
    if (now > 1 && d[now-1] > d[now] + x) {
      d[now-1] = d[now] + x;
      if (!inside[now-1]) {
        inside[now-1] = 1;
        q.push(now-1);
      }
    }
    if (now < 2 * n && d[now+1] > d[now] + x) {
      d[now+1] = d[now] + x;
      if (!inside[now+1]) {
        inside[now+1] = 1;
        q.push(now+1);
      }    }
    if (now < n && d[2 * now] > d[now] + y) {
      d[now * 2] = d[now] + y;
      if (!inside[2 * now]) {
        inside[2 * now] = 1;
        q.push(2 * now);
      }
    }
  }
  cout << d[n] << endl;
  return 0;
} 