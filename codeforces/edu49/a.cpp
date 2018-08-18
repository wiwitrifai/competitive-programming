#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N];
int n;

bool solve() {
  for (int i = 0, j = n-1; i < j; ++i, --j) {
    if (s[i] == s[j]) continue;
    if (abs(s[i]-s[j]) == 2) continue;
    return false;
  }
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s", &n, s);
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}