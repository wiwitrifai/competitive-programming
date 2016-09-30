#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int now = 0;
  vector< int > ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      now++;
    else {
      if (now)
        ans.push_back(now);
      now = 0;
    }
  }
  if (now)
    ans,push_back(now);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}