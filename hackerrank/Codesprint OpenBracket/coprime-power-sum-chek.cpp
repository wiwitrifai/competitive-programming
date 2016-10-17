#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;
const long long M = 1LL * N * N;

bitset< N > bs;

int main() {
  vector< int > p;
  for (int i = 2; i < N; i++) if (!bs[i]) {
    printf("%d ", i);
    p.push_back(i);
    if (p.size() > 50)
      break;
    for (long long j = 1LL * i * i; j < N; j += i)
      bs[j] = 1;
  }
  vector < long long > vs;
  vs.push_back(1);
  for (int i = 0; i < 50; i++) {
    int n = vs.size();
    for (int j = 0; j < n; j++)
      if (vs[j] * p[i] < M)
        vs.push_back(vs[j] * p[i]);
  }
  cout << vs.size() << endl;
  return 0;
}