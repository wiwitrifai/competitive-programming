#include <bits/stdc++.h>

using namespace std;

char buff[105];

int main() {
  int n;
  scanf("%d", &n);
  bool ans = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buff);
    if (buff[0] == 'L')
      ans = !ans;
  }
  puts(ans ? "TRUTH" : "LIE");
  return 0;
}