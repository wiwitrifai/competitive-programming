#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i+1] < s[i]) {
      puts("YES");
      printf("%d %d\n", i+1, i+2);
      return 0;
    }
  }
  puts("NO");
  return 0;
}
