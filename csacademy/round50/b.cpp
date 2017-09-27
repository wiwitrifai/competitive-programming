#include <bits/stdc++.h>

using namespace std;

int m[] = {31,28,31,30,31,30,31,31,30,31,30,31};
string s[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
map<string, int> to;

int main() {
  for (int i = 0; i < 7; i++) {
    to[s[i]] = i;
  }
  string st;
  cin >> st;
  int now = to[st];
  int ans = 0;
  now += 12;
  now %= 7;
  for (int i = 0; i < 12; i++) {
    now %= 7;
    ans += (now == 4);
    now += m[i];
  }
  printf("%d\n", ans);
  return 0;
}