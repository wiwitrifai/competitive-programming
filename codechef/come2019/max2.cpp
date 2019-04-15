#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = 0;
  while (ans < n && s[n-1-ans] == '0') ++ans;
  printf("%d\n", ans);
  return 0;
}
