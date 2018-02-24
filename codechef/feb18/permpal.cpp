#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N], res[N];
int cnt[26];
vector<int> id[26];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n =strlen(s);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < 26; ++i) id[i].clear();
    for (int i = 0; i < n; ++i)
      s[i] -= 'a', ++cnt[s[i]], id[s[i]].push_back(i);
    int ganjil = 0;
    for (int i = 0; i < 26; ++i) {
      ganjil += cnt[i] & 1;
    }
    if (ganjil > 1) {
      puts("-1");
      continue;
    }
    for (int i = 0, l = 0, r = n-1; i < 26; ++i) {
      while (cnt[i] >= 2) {
        cnt[i] -= 2;
        res[l++] = i;
        res[r--] = i;
      }
    }
    if (n & 1)
      for (int i = 0; i < 26; ++i)
        if (cnt[i])
          res[n/2] = i;
    for (int i = 0; i < n; ++i) {
      printf("%d%c", id[res[i]].back() + 1, i == n-1 ? '\n' : ' ');
      id[res[i]].pop_back();
    }
  }
  return 0;
}