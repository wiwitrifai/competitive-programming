#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], t[N];

int main() {
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t);
  int i = 0, j = 0;
  while(n-i > m-j) {
    if(s[i] != '0') {
      puts(">");
      return 0;
    }
    i++;
  }
  while(n-i < m-j) {
    if(t[j] != '0') {
      puts("<");
      return 0;
    }
    j++;
  }
  for(; i<n; i++) {
    if(s[i] < t[j]) {
      puts("<");
      return 0;
    }
    else if(s[i] > t[j]) {
      puts(">");
      return 0;
    }
    j++;
  }
  puts("=");
  return 0;
}