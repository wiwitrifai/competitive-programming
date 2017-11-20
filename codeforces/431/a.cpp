#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int main() {
  int k; 
  scanf("%d", &k);
  int n = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    int cnt = 0;
    while (k >= cnt) k -= cnt, cnt++;
    while (cnt > 0) {
      s[n++] = c;
      cnt--;
    }
  }
  s[n] = '\0';
  printf("%s\n", s);
  return 0;
}