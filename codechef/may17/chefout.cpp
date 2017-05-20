#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N], c[10] = "CES";

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s), j = 0;
    for (int i = 0; i < n; i++) {
      while (j < 4 && s[i] != c[j]) j++;
    }
    puts(j < 4 ? "yes" : "no");
  }
  return 0;
}