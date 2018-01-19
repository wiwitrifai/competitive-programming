#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    s[n] = s[0];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += s[i] != s[i+1];
    }
    puts(cnt <= 2 ? "uniform" : "non-uniform");
  }
  return 0;
}
