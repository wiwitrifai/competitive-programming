#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 4;

char s[N];

bool ispal(string ss) {
  for (int l = 0, r = (int)ss.size()-1; l < r; ++l, --r)
    if (ss[l] != ss[r])
      return false;
  return true;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool same = 1;
  for (int l = 0, r = n-1; l < r; ++l, --r) {
    same &= s[l] == s[0] && s[r] == s[0];
  }
  if (same) {
    puts("Impossible");
    return 0;
  }
  string ss = s;
  for (int i = 1; i < n; ++i) {
    string res = ss.substr(i, n-i) + ss.substr(0, i);
    if (res != ss && ispal(res)) {
      puts("1");
      return 0;
    }
  }
  puts("2");
  return 0;
}