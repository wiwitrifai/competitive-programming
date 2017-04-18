#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
vector< int > prime;
bitset< N > isp;
long long val[N];
vector< int > d[N];

int main() {
  isp.set();
  for (int i = 2; i < N; i++) if (isp[i]) {
    prime.push_back(i);
    for (long long j = 1LL * i * i; j < N; j += i)
      isp[j] = 0;
  }
  long long a, b;
  cin >> a >> b;
  int n = b-a + 1;
  for (int i = 0; i < n; i++) {
    val[i] = a + i;
  }
  for (int p : prime) {
    long long now = ((a+p-1)/p) * p;
    now -= a;
    for (; now < n; now += p) {
      int cnt = 0;
      while ((val[now] % p) == 0) {
        val[now] /= p;
        cnt++;
      }
      d[now].push_back(cnt);
    }
  }
  for (int i = 0; i < n; i++) {
    if (val[i] > 1)
      d[i].push_back(1);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long cur = 1, now = 0;
    priority_queue< int > pq;
    for (int v : d[i]) {
      cur *= v + 1;
      pq.push(v);
    }
    while (!pq.empty()) {
      now += cur;
      int v = pq.top();
      pq.pop();
      cur /= v+1;
      v--;
      if (v) {
        cur *= v+1;
        pq.push(v);
      }
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}