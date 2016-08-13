#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  int ma = 0;
  for (int i = 0; i < n; i++) {
    ma += max(abs(s[i]-'a'), abs(s[i]-'z'));
  }
  if (k > ma)
    puts("-1");
  else {
    for(int i = 0; i<n; i++) {
      if (abs(s[i]-'a') > abs(s[i]-'z')) {
        int d = min(k, abs(s[i]-'a'));
        s[i] -= d;
        k -= d;
      }
      else {
        int d = min(k, abs(s[i]-'z'));
        s[i] += d;
        k -= d; 
      }
    }
    printf("%s\n", s);
  }

  return 0;
}