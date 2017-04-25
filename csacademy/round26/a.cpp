#include <bits/stdc++.h>

using namespace std;

char s[1000];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = -1;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    set< char > st;
    for (int j = 0; j < len; j++)
      st.insert(s[j]);
    if (st.size() <= k)
      if (ans < len)
        ans = len;
  }
  printf("%d\n", ans);
  return 0;
}