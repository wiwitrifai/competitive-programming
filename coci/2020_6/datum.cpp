#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while (n--) {
    int d, m, y;
    scanf("%d.%d.%d.", &d, &m, &y);
    int nowy = y;
    while (true) {
      int cur = nowy;
      int nowm = 0, nowd = 0;
      nowd = cur % 10;
      cur /= 10;
      nowd = nowd * 10 + (cur % 10);
      cur /= 10;
      nowm = cur % 10;
      cur /= 10;
      nowm = nowm * 10 + cur % 10;
      if (nowm < 1 || nowm > 12) {
        ++nowy;
        continue;
      }
      int cnt = days[nowm-1];
      if (nowm == 2 && (nowy % 4) == 0)
        ++cnt;
      if (nowd < 1 || nowd > cnt) {
        ++nowy;
        continue;
      }
      if (make_tuple(y, m, d) >= make_tuple(nowy, nowm, nowd)) {
        ++nowy;
        continue;
      }
      printf("%02d.%02d.%04d.\n", nowd, nowm, nowy);
      break;
    }
  }
  return 0;
}
