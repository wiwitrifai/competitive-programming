#include <bits/stdc++.h>

using namespace std;

string s;
int k;
int get(int w) {
  int ret = 1, last = -1, cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    cnt++;
    if (cnt > w)
      ret++, cnt = i-last;
    if (cnt > w)
      return k+1;
    if (s[i] == '-')
      last = i;
  }
  return ret;
}

int main() {
  cin >> k;
  s = "";
  while (s.empty()) getline(cin, s);
  for (int i = 0; i < s.size(); i++)
    if (s[i] == ' ')
      s[i] = '-';
  int l = 0, r = s.size();
  while (l < r) {
    int m = (l + r) >> 1;
    if (get(m) > k)
      l = m+1;
    else
      r = m;
  }
  printf("%d\n", l);
  return 0;
}