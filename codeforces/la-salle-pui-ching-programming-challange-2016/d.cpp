#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int score = 0, ten = 0, x = 0;
  for (int i = -1; i < 2; i += 2) {
    for (int j = 0; j < n; j++) {
      string s;
      cin >> s;
      if (s[0] == 'X')
        ten += i, x += i, score += i * 10;
      else if (s[0] != 'M'){
        int val = stoi(s);
        score += i * val;
        if (val == 10)
          ten += i;
      }
    }
  }
  pair<int, pair<int, int> > res = {score, {ten, x}}, imbang = {0, {0, 0}};
  if (res < imbang)
    puts("Yuju");
  else if (res > imbang)
    puts("Yerin");
  else
    puts("Shoot-off");
  return 0;
}