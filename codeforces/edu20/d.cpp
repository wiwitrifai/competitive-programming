#include <bits/stdc++.h>

using namespace std;

string s;
int h;
bool can(int x) {
  int cnt = 0, last = -1, now = 0;
  for (int i = 0; i < s.size(); i++) {
    now++;
    if (now > x) {
      now = i-last;
      cnt++;
    }
    if (now > x)
      return 0;
    if (s[i] == ' ' || s[i] == '-')
      last = i;
  }
  if (now > 0)
    cnt++;
  return cnt <= h;
}

int main() {
  cin >> h;
  getline(cin, s);
  if (s.empty())
    getline(cin, s);
  int l = 0, r = s.size();
  while (l < r) {
    int mid = (l + r)/2;
    if (can(mid))
      r = mid;
    else
      l = mid+1;
  }
  printf("%d\n", l);
  return 0;
}