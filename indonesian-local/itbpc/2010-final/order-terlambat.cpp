
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long t[N], a[N], b[N];
int id[N];

int main() {
  int p;
  scanf("%d", &p);
  while (p--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld %lld", t+i, a+i, b+i);
      id[i] = i;
    }
    sort(id, id+n, [](int le, int ri) {
      return t[le] * b[ri] < t[ri] * b[le];
    });
    long long now = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      now += t[id[i]];
      ans += a[id[i]] + now * b[id[i]];
    }
    printf("%lld\n", ans);
  }

  return 0;
}