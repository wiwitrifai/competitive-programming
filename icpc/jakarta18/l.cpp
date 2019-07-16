#include <bits/stdc++.h>

using namespace std;

char s[77];

int main() {
  long long n;
  scanf("%lld %s", &n, s);
  long long cur = 0;
  int len = strlen(s);
  for (int i = 0; i < len; ++i)
    cur = cur * 2 + (s[i]-'0');
  int ans = 0;
  while (cur > n) {
    ++ans;
    vector<int> hidup;
    for (int i = 0; (1LL << i) <= cur; ++i) {
      if (cur & (1LL << i))
        hidup.push_back(i);
    }
    cur = 0;
    for (int i = 0; i+2 < hidup.size(); ++i)
      cur |= 1LL << hidup[i];
    cur |= 1LL << (hidup.back()-1);
  }
  printf("%d\n", ans);
  return 0;
}