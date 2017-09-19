#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
char s[N];

bool can(int x) {
  int j = 0, i = 0;
  while (i < n && j < n) {
    // cerr << i << " " << j << " " << x << endl;
    while (j < n && s[j] != '*') j++;
    if (j == n) return true;
    while (i < n && s[i] != 'P') i++;
    if (i == n) return false;
    // cerr << i << " " << j << " " << x << endl;
    if (j > i) {
      if (j - i > x) {
        i++;
        continue;
      }
      j = i + x + 1;
      i++;
    }
    else {
      if (i - j > x) return false;
      int len = max(x - (i - j), (i-j) + (x - (i-j))/2);
      j = j + len + 1;
      i++;
    }
  }
  return j >= n;
}

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int lo = 0, ri = 2 * n;
  while (lo < ri) {
    int mid = (lo + ri) / 2;
    if (can(mid))
      ri = mid;
    else
      lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}