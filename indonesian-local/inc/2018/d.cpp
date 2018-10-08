#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N], p[N];
int cnt[256];

int main() {
  scanf("%s %s", s, p);
  int len = strlen(s);
  for (int i = 0; i < len; ++i)
    ++cnt[s[i]-'a'];
  len = strlen(p);
  for (int i = 0; i < len; ++i)
    --cnt[p[i]-'a'];
  bool ok = 1;
  for (int i = 0; i < 26; ++i) {
    ok &= cnt[i] >= 0;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}