#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int cnt[N], p[N];
int leaf[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", p+i);
    p[i]--;
    cnt[p[i]]++;
  }
  for (int i = 1; i < n; ++i) if (cnt[i] == 0) {
    leaf[p[i]]++;
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 0) continue;
    // cerr << i << " " << cnt[i] << endl;
    ok &= leaf[i] >= 3;
  }
  puts(ok ? "Yes" : "No");

  return 0;
}