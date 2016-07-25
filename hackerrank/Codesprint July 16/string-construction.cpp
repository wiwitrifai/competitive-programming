#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
bool b[256];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    memset(b, 1, sizeof b);
    int ans = 0;
    for(int i = 0; i<n; i++) {
      ans += b[s[i]];
      b[s[i]] = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}