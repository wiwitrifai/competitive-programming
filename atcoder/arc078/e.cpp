#include <bits/stdc++.h>

using namespace std;

bool ask(long long n) {
  printf("? %lld\n", n);
  fflush(stdout);
  char s[10];
  scanf("%s", s);
  return s[0] == 'Y';
}

void answer(long long n) {
  printf("! %lld\n", n);
  fflush(stdout);
}

int main() {
  long long n = (long long)(1e9);
  int k = 9;
  if (ask(n)) {
    n /= 5;
    while (k > 0 && ask(n)) n /= 10, k--;
    if (k == 0)
      answer(1);
    else
      answer(n * 5);
  }
  else {
    n/= 10, k--;
    while (k > 0 && !ask(n)) n /= 10, k--;
    long long ans = 0;
    for (int i = 0; i <= k; i++) {
      int l = 0, r = 9;
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (ask((ans + n * mid) * 10))
          r = mid-1;
        else
          l = mid;
      }
      ans += l * n;
      n /= 10;
    }
    answer(ans+1);
  }
  return 0;
}