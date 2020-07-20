#include <bits/stdc++.h>

using namespace std;

const int N = 55, K = 7;

char t[10] = "abacaba";
char s[N];

void solve() {
  int n;
  scanf("%d %s", &n, s);
  auto calc = [](string str, int pos) {
    for (int i = 0; i < K; ++i) {
      if (str[pos+i] == '?')
        str[pos+i] = t[i];
      if (str[pos+i] != t[i])
        return string();
    }
    for (int i = 0; i < (int)str.size(); ++i)
      if (str[i] == '?')
        str[i] = 'z';
    int cnt = 0;
    for (int i = 0; i+K <= (int)str.size(); ++i) {
      bool ok = 1;
      for (int j = 0; j < K; ++j) {
        if (str[i+j] != t[j]) {
          ok = 0;
          break;
        }
      }
      cnt += ok;
    }
    if (cnt == 1)
      return str;
    else
      return string();
  };
  for (int i = 0; i+K <= n; ++i) {
    string res = calc(s, i);
    if (!res.empty()) {
      puts("Yes");
      printf("%s\n", res.c_str());
      return;
    }
  }
  puts("No");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
