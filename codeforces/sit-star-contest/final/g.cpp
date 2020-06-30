#include <bits/stdc++.h>

using namespace std;

int main() {
  int s;
  scanf("%d", &s);
  if (s == 1) {
    puts("1");
    return 0;
  }
  if ((s & 1) == 0) {
    puts("-1");
    return 0;
  }
  int a = (s - 1) / 2;
  string res = "";
  if (a < 8) {
    if (a & 1) {
      res = "10";
      res[1] += a - 1;
    } else {
      res = "0";
      res[0] += a;
    }
  } else {
    res.push_back('8');
    a -= 8;
    while (a > 0) {
      int d = min(a, 9);
      res.push_back('0' + d);
      a -= d;
    }
    reverse(res.begin(), res.end());
  }
  printf("%s ", res.c_str());
  res.back()++;
  printf("%s\n", res.c_str());
  return 0;
}
