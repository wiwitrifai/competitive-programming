#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

char s[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%s", s);
    int n = strlen(s);
    if(n == 1) {
      puts("NO");
      continue;
    }
    bool ans = false;
    if(n % 2 == 1) {
      int len = n/2, i, j;
      for(i = 0, j = len; j<n; j++)
        if(s[i] == s[j])
          i++;
      if(i == len)
        ans = true;
      else {
        len++;
        for(i = 0, j = len; i<len; i++)
          if(s[i] == s[j])
            j++;
        if(j == n)
          ans = true;
        else
          ans = false;
      }
    }
    else {
      n /= 2;
      ans = true;
      for(int i = 0; i<n; i++) {
        if(s[i] != s[n+i]) {
          ans = false;
          break;
        }
      }
    }
    puts(ans ? "YES" : "NO");
  }
  return 0;
}