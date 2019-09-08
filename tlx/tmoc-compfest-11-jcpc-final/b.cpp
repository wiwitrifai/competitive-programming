#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  vector<int> zero;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0')
      zero.push_back(i);
  }
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    bool can = 1;
    int last = 0;
    for (int x : zero) {
      while (last < n && s[last] == '0') ++last;
      int cnt = 0;
      if (last < x) {
        cnt += x - last;
        last = x+1;
      }
      if (cnt > mid) {
        can = 0;
        break;
      }
      if (last == x+1) {
        int sisa = mid - cnt;
        while (last < n && sisa > 0 && s[last] == '1') {
          ++last;
          ++cnt;
          --sisa;
        }
      }
      if (cnt > mid) {
        can = 0;
        break;
      }
    }
    can &= last >= n;
    if (can)
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}
