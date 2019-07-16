#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int sp[N];
int last[N];
long long rem[N];

int main() {
  for (int i = 2; i < N; ++i) {
    if (sp[i] != 0) continue;
    for (int j = i; j < N; j += i)
      if (sp[j] == 0)
        sp[j] = i;
  }
  memset(last, -1, sizeof last);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    while (a > 1) {
      int p = sp[a];
      while ((a % p) == 0) a /= p;
      int cnt = i - last[p] - 1;
      rem[p] += 1LL * cnt * (cnt + 1) / 2;
      last[p] = i;
    }
  }
  long long ans = 0;
  for (int i = 2; i < N; ++i) {
    if (sp[i] != i) continue;
    int cnt = n - last[i] - 1;
    rem[i] += 1LL * cnt * (cnt + 1) / 2;
    // cerr << i << " " << rem[i] << endl;
    ans += 1LL * n * (n + 1) / 2 - rem[i];
  }
  printf("%lld\n", ans);
  return 0;
}