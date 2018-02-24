#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int ans =0;
    for (int i = 0; i + 4 <= n; ++i) {
      string cur(s+i, s+i+4);
      sort(cur.begin(), cur.end());
      ans += cur == "cefh";
    }
    if (ans == 0)
      puts("normal");
    else
      printf("lovely %d\n", ans);
  }
  return 0;
}