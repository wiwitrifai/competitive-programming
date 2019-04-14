#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  if (n & 1) {
    puts(":(");
    return 0;
  }
  int open = n/2;
  for (int i = 0; i < n; ++i)
    if (s[i] == '(')
      --open;
  for (int i = 0; i < n && open > 0; ++i) {
    if (s[i] != '?') continue;
    s[i] = '(';
    --open;
  }
  for (int i = 0; i < n; ++i)
    if (s[i] == '?')
      s[i] = ')';
  bool ok = 1;
  int val = 0;
  for (int i = 0; i < n-1; ++i) {
    val += s[i] == '(' ? 1 : -1;
    if (val <= 0) {
      ok = 0;
      break;
    }
  }
  val += s[n-1] == '(' ? 1 : -1;
  if (val != 0)
    ok = 0;
  printf("%s\n", ok ? s : ":(");
  return 0;
}