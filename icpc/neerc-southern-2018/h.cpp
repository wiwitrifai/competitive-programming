#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

char s[N][10];
int c2i(char c) {
  if ('a' <= c && c <= 'z')
    return c - 'a' + 1;
  if ('0' <= c && c <= '9')
    return c - '0' + 27;
  if (c == '.')
    return 37;
  assert(false);
  return 0;
}

char t[109];

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<long long, int> > all;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    int len = strlen(s[i]);
    vector<long long> hs;
    for (int j = 0; j < len; ++j) {
      long long now = 0;
      for (int k = j; k < len; ++k) {
        now *= 38;
        now += c2i(s[i][k]);
        hs.push_back(now);
      }
    }
    sort(hs.begin(), hs.end());
    hs.erase(unique(hs.begin(), hs.end()), hs.end());
    for (long long v : hs)
      all.emplace_back(v, i);
  }
  s[n][0] = '-';
  s[n][1] = '\0';
  sort(all.begin(), all.end());
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%s", t);
    int len = strlen(t);
    long long now = 0;
    for (int i = 0; i < len; ++i) {
      now *= 38;
      now += c2i(t[i]);
    }
    int sel = n;
    auto low = lower_bound(all.begin(), all.end(), make_pair(now, -1));
    auto upp = upper_bound(all.begin(), all.end(), make_pair(now+1, -1));
    int cnt = upp - low;
    if (cnt)
      sel = low->second;
    printf("%d %s\n", cnt, s[sel]);
  }
  return 0;
}