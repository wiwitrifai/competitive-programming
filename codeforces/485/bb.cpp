#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], cyc[N], used[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i); --a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    int u = i;
    int cnt = 0;
    while (!used[u]) {
      ++cnt;
      used[u] = 1;
      u = a[u];
    }
    mp[cnt]++;
  }
  int tot =0;
  for (int i = 0; i <= 3; ++i)
    tot += mp[i];
  if (mp[1] > 10) {
    puts("Petr");
    return 0;
  }
  if (mp[
  return 0;
}