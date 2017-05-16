#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long tot = 0;
  map< long long, int > mp;
  mp[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a+i);
    tot += a[i];
    mp[tot] = i;
  }
  if (tot & 1) {
    puts("NO");
    return 0;
  }
  tot /= 2;
  if (mp.count(tot)) {
    puts("YES");
    return 0;
  }
  bool ok = 0;
  for (int i = 1; i <= n; i++) {
    long long val = tot - a[i];
    auto it = mp.find(val);
    if (it != mp.end()) {
      if (it->second < i) {
        ok = 1;
        break;
      }
    }
    val = tot + a[i];
    it = mp.find(val);
    if (it != mp.end()) {
      if (it->second >= i) {
        ok = 1;
        break;
      }
    }
  }
  puts(ok ? "YES" : "NO");
  return 0;
}