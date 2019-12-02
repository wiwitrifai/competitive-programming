#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  vector<pair<char, int>> compress;
  char last = s[0];
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != last) {
      compress.emplace_back(last, cnt);
      cnt = 0;
      last = s[i];
    }
    ++cnt;
  }
  compress.emplace_back(last, cnt);
  if ((compress.size() & 1) == 0) {
    puts("0");
    return 0;
  }
  int l = 0, r = (int)compress.size()-1;
  bool ok = 1;
  while (l < r) {
    ok &= compress[l].first == compress[r].first;
    ok &= (compress[l].second + compress[r].second) >= 3;
    ++l;
    --r;
  }
  ok &= compress[l].second >= 2;
  printf("%d\n", ok ? compress[l].second+1 : 0);
  return 0;
}
