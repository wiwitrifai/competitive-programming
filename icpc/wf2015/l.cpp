#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long C[N][N];

double p[4];

priority_queue<pair<double, long long> > pq;

void gen(int n, int pos, double d = 1, long long cnt = 1) {
  if (pos < 0) {
    if (n != 0) return;
    pq.push(make_pair(-d, cnt));
    return;
  }
  for (int j = 0; j <= n; ++j) {
    gen(n-j, pos-1, d, cnt * C[n][j]);
    d *= p[pos];
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 4; ++i) {
    scanf("%lf", p+i);
  }
  gen(n, 3);
  double ans = 0;
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    if (it.second == 1) {
      if (pq.empty()) break;
      double prob = it.first;
      it = pq.top(); pq.pop();
      ans += prob + it.first;
      --it.second;
      pq.push(make_pair(prob + it.first, 1));
      if (it.second > 0)
        pq.push(it);
    }
    else {
      if (it.second & 1) {
        --it.second;
        pq.push(make_pair(it.first, 1));
      }
      it.first *= 2;
      it.second /= 2;
      ans += it.first * it.second;
      pq.push(it);
    }
  }
  printf("%.20lf\n", -ans);
  return 0;
}
