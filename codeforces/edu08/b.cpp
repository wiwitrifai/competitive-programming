#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    if (i) {
      int bil = (s[i-1]-'0') * 10 + s[i]-'0';
      if((bil % 4) == 0)
        ans += i;
    }
    if (((s[i]-'0') % 4) == 0)
      ans++;
  }
  printf("%I64d\n", ans);
  return 0;
}