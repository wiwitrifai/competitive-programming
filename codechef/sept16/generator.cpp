#include <bits/stdc++.h>

using namespace std;
const int N = 5e4 + 5;

int x[N], y[N], r[N];

int main() {
  int n, m, mod, modr;
  srand(0);
  scanf("%d %d %d %d", &n, &m, &mod, &modr);
  printf("%d %d\n", n, m);
  cerr << n << " " << m << endl;
  for (int i = 0; i < n; i++) {
    bool ok = false;
    while (!ok) {
      ok = true;
      x[i] = rand() % mod;
      y[i] = rand() % mod;  
      r[i] = rand() % modr + 1;
      for (int j = 0; j < i; j++) {
        long long dx = x[i] - x[j],
        dy = y[i] - y[j], dr = r[i] + r[j];
        if (dx * dx + dy * dy <= dr * dr)
          ok = false;
      }
    }
    printf("%d %d %d\n", x[i], y[i], r[i]);
  }
  for (int i = 0; i < m; i++) {
    int a = rand() % mod, b = rand() % mod + a + 1, c = rand() % mod, d = rand() % mod + c + 1;
    printf("%d %d %d %d\n", a, c, b, d);
  }


  return 0;
}