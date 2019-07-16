#include <bits/stdc++.h>

using namespace std;

const int N = 1e5, M = 10;

int p[11];

int main() {
  srand(time(0));
  int n = (rand() % N) + 1;
  int m = (rand() % M) + 1;
  int k = (rand() % N) + 1;
  int ma = 1;
  for (int i = 0; i < n; ++i) {
    long long mul = 1LL * ma * m;
    if (mul > k)
      mul = k;
    ma = mul;
  }
  k = ma;
  for (int i = 0; i < 10; ++i)
    p[i] = i;
  random_shuffle(p, p+10);
  printf("%d %d %d\n", n, m, k);
  cerr << n << " " << m << " " << k << endl;
  for (int i = 0; i < m; ++i) {
    printf("%d%c", p[i], i == m-1 ? '\n' : ' ');
  }
  return 0;
}