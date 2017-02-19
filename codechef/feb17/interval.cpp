#include <bits/stdc++.h>


using namespace std;

const int N = 3e5 + 5;

struct rmq {
  deque< long long > dq;
  rmq() {
  }
  void add(long long x) {
    while (!dq.empty() && dq.back() < x)
      dq.pop_back();
    dq.push_back(x);
  }
  void del(long long x) {
    if (!dq.empty() && dq.front() == x)
      dq.pop_front();
  }
  long long get() {
    return dq.empty() ? 0 : dq.front();
  }
};
long long sum[N], a[N];
int b[1024];
long long val[2][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a+i);
      sum[i+1] = sum[i] + a[i];
    }
    for (int i = m; i > 0; i--)
      scanf("%d", b+i);
    b[0] = 1;
    int cur = 0, bef = 1;
    for (int i = 0; i < n; i++)
      val[cur][i] = 0;
    for (int i = 1; i <= m; i++) {
      bef ^= 1;
      cur ^= 1;
      rmq mq;
      for (int j = 1; j + b[i-1] < b[i]; j++)
        mq.add(val[bef][j]);
      for (int j = 0; j + b[i] <= n; j++) {
        val[cur][j] = sum[j+b[i]] - sum[j] - mq.get();
        if (b[i]-b[i-1] > 1) {
          mq.add(val[bef][j+b[i]-b[i-1]]);
          mq.del(val[bef][j+1]);
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i + b[m] <= n; i++)
      ans = max(ans, val[cur][i]);
    printf("%lld\n", ans);
  }
  return 0;
}