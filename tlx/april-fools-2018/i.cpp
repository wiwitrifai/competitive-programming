#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  bool car = 0;
  while (cin >> s) {
    for (int i = 0; i < s.size(); ++i)
      car |= s[i] == 'N';
  }
  puts(car ? "CAR" : "PLANE");
  return 0;
}