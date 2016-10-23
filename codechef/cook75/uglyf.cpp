#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, inf = 1e8;
vector< pair< int, int > > petal[26];

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < 26; i++)
      petal[i].clear();
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'A';
      int a = i, b = n-1 - i;
      if (a > b)
        swap(a, b);
      petal[c].push_back({a, b});
    }
    for (int i = 0; i < 26; i++) {
      sort(petal[i].begin(), petal[i].end());
      reverse(petal[i].begin(), petal[i].end());
      if (petal[i].size() > 10) {
        petal[i].erase(petal[i].begin() + 10, petal[i].end());
      }
    }
    scanf("%s", s);
    n = strlen(s);
    int ans = inf;
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'A';
      int a = i, b = n-1 - i;
      for (auto it : petal[c]) {
        ans = min(ans, abs(it.first - a) + abs(it.first - b) + abs(it.second - a) + abs(it.second - b));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}