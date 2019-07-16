#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
  int sum = 0;
  bool doubl = 1;
  for (int i = (int)s.size()-2; i >= 0; --i) {
    int now = s[i] - '0';
    if (doubl) {
      now  *= 2;
      if (now >= 10)
        now = (now / 10) + (now % 10);
    }
    sum += now;
    doubl = !doubl;
  }
  sum = sum * 9 % 10;
  return (sum == s.back() - '0');
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  int pos = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == 'x')
      pos = i;
  for (int d = 0; d < 10; ++d) {
    s[pos] = '0' + d;
    if (check(s)) {
      printf("%d\n", d);
      return 0;
    }
  }
  return 0;
}