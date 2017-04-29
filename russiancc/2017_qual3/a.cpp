#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    cin >> n;
    int dig = 1;
    long long cnt = 26;
    while (cnt < n) n -= cnt, dig++, cnt *= 26;
    for (int i = 0; i < dig; i++) {
      cnt /= 26;
      int now = 0;
      while (n > cnt) now++, n -= cnt;
      printf("%c", now + 'A');
    }
    printf("\n");
  }
  return 0;
}