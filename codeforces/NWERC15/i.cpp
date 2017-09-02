#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  long long x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    x <<= 1;
    y <<= 1;
    int now = s[i] - '0';
    if (now & 1)
      x += 1;
    if (now & 2)
      y += 1;
  }
  cout << n << " " << x << " " << y << endl;
  return 0;
}