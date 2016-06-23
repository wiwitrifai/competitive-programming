#include <bits/stdc++.h>

using namespace std;

int get(int y) {
  if((y % 400) == 0)
    return 2;
  if((y % 100) == 0)
    return 1;
  if((y % 4) == 0)
    return 2;
  return 1;
}

int main() {
  int y;
  int x;
  cin >> y;
  x = y;
  int now = 0;
  now += get(y++);
  while(now != 0 || get(y) != get(x)) {
    now = (now + get(y++)) % 7;
  }
  cout << y << endl;

  return 0;
}