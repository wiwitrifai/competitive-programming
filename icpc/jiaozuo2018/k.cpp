// TLE
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, S = sqrt(N);

int trie[N][26];

pair<int, int> go[N/S + 2][N];
char s[N];

void solve() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 26; ++j)
      trie[i][j] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int f;
    scanf("%d %s", &f, s);
    trie[f][s[0]-'a'] = i;
  }
  scanf("%s", s);
  for (int j = 0; j < m; ++j)
    s[j] -= 'a';
  for (int i = 0; i < m; i += S) {
    int til = min(i + S, m);
    int id = i / S;
    for (int st = 0; st <= n; ++st) {
      int now = st, fail = 0;
      for (int j = i; j < til; ++j) {
        now = trie[now][s[j]];
        fail += now == 0;
      }
      go[id][st] = {now, fail};
    }
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int c = l / S;
    int now = 0, fail = 0;
    if (l > c * S) {
      ++c;
      int til = min(c * S, r);
      while (l < til) {
        now = trie[now][s[l]];
        fail += now == 0;
        ++l;
      }
    }
    while ((c + 1) * S <= r) {
      fail += go[c][now].second;
      now = go[c][now].first;
      ++c;
      l = c * S;
    }
    while (l < r) {
      now = trie[now][s[l]];
      fail += now == 0;
      ++l;
    }
    printf("%d %d\n", fail, now);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
