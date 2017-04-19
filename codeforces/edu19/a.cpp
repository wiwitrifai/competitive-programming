#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int f[N];

int main() {
  f[1] = 1;
  for (int i = 2; i < N; i++) if (f[i] == 0) {
    for (int j = i; j < N; j += i)
      if (f[j] == 0)
        f[j] = i;
  }
  int n, k;
  scanf("%d %d", &n, &k);
  vector< int > ans;
  k--;
  while (k-- > 0 && n > 1) {
    ans.push_back(f[n]);
    n /= f[n];
  }
  if (n == 1)
    puts("-1");
  else {
    for (int v : ans)
      printf("%d ", v);
    printf("%d\n", n);
  }
  return 0;
}