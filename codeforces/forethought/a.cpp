#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += (s[i] == 'a'); 
  int ans = cnt + min(n-cnt, cnt-1);
  printf("%d\n", ans);
  return 0;
}
