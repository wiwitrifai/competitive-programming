#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

char s[N];

int pre[N], mpre[N];
int suf[N], msuf[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int open = 0;
  for (int i = 0; i < n; ++i) {
    open += s[i] == '(';
  }
  if (open != n - open) {
    puts("0");
    return 0;
  }
  pre[0] = mpre[0] = 0;
  for (int i = 0; i < n; ++i) {
    pre[i+1] = pre[i] + (s[i] == '(' ? +1 : -1);
    mpre[i+1] = min(mpre[i], pre[i+1]);
  }
  suf[n] = msuf[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    suf[i] = suf[i+1] + (s[i] == ')' ? +1 : -1);
    msuf[i] = min(msuf[i+1], suf[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (msuf[i] >= pre[i] && mpre[i] >= suf[i])
      ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
