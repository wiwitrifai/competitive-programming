#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 1;
  for(int i = 0; i<n; i++)
    ans += (s[i] <= 'Z' && s[i] >= 'A');
  printf("%d\n", ans);

  return 0;
}