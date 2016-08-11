#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 1; i<n; i++) {
    if(s[i] == s[i-1]) {
      s[i] = 'a';
      if(s[i] == s[i-1])
        s[i]++;
      if(s[i] == s[i+1])
        s[i]++;
      if(s[i] == s[i-1])
        s[i]++;
    }
  }
  printf("%s\n", s);

  return 0;
}