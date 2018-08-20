#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int cnt[256];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]];
  }
  bool ok = n == 1;
  for (int i = 0; i < 256; ++i) {
    ok |= cnt[i] > 1;
  }
  puts(ok ? "Yes" : "No");
  return 0;
}