#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
      if (s[i] == s[0])
        pos.push_back(i);
    }
    int ans = 1;
    while (ans < n) {
      bool ok = 1;
      for (int u : pos) {
        if  (u + ans >= n || s[u+ans] != s[ans]) {
          ok = 0;
          break;
        }
      }
      if (!ok) break;
      ++ans;
    }
    s[ans] = '\0';
    printf("%s\n", s);
  }
  return 0;
}