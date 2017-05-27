#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int main() {
  long long k;
  scanf("%s %lld", s, &k);
  int n = strlen(s);
  k--;
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '_') {
      s[i] = (k % 26) + 'a';
      k /= 26;
    }
  }
  printf("%s\n", s);
  return 0;
}