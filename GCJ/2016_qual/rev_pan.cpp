#include <bits/stdc++.h>

using namespace std;

char s[212];
int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    printf("Case #%d: ", tc);
    scanf("%s", s);
    int n = strlen(s);
    int ans = (s[n-1] == '-');
    for(int i = 1; i<n; i++)
      if(s[i] != s[i-1])
        ans++;
    cerr << "TC #" << tc << "\n";
    printf("%d\n", ans);
  }
  return 0;
}