#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  int mid = n / 2;
  ans = mid;
  while (ans < n) {
    if (s[ans] != s[n-1-ans] || s[ans] != s[mid]) break;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}