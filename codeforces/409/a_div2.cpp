#include <bits/stdc++.h>

using namespace std;

const int N = 103;

char s[N];

int count(int n) {
  int ans = 0;
  for (int i = 0; i+1 < n; i++) {
    ans += (s[i] == 'V' && s[i+1] == 'K');
  }
  return ans;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = count(n);
  for (int i = 0; i < n; i++) {
    s[i] = 'V' + 'K' - s[i];
    ans = max(ans, count(n));
    s[i] = 'V' + 'K' - s[i];
  }
  printf("%d\n", ans);
  return 0;
}