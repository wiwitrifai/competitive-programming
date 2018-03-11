// by wiwit
#include <bits/stdc++.h>

using namespace std;
const string filename = "foreign";

const int N = 1e6 + 6;

char s[N];
long double dp[N];

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif
  scanf("%s", s);
  int n = strlen(s);
  long long w = 0, c = 0;
  long double sum = 0;
  reverse(s, s+n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W')
      w += (i+1);
    else
      c += (i+1);
    if (s[i] == 'W') {
      dp[i] = (sum + c)/(i+1);
    }
    else
      dp[i] = (sum + w)/(i+1);
    sum += dp[i];
  }
  printf("%.12lf\n", (double)dp[n-1]);

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  return 0;
}