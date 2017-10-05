#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, m, s, a, b;
  scanf("%d %d %d %d %d", &h, &m, &s, &a, &b);
  if (a > b)
    swap(a, b);
  if (a == b) {
    puts("YES");
    return 0;
  }
  int put = 12 * 60 * 60;
  a *= 60 * 60;
  b *= 60 * 60;
  h = h * 3600 + m * 60 + s;
  m = (m * 60 + s) * 12;
  s *= put/60;
  int le = 0, ri = 0;
  if (a < h && h < b)
    le++;
  else ri++;
  if (a < m && m < b)
    le++;
  else ri++;

  if (a < s && s < b)
    le++;
  else ri++;
  puts( (le == 0 || ri == 0) ? "YES" : "NO");
  return 0;
}