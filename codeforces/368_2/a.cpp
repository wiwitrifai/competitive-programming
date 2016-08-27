#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool colorful = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      scanf(" %c", &c);
      switch(c) {
        case 'C':
        case 'M':
        case 'Y':
          colorful = true;
      }
    }
  }
  puts(colorful ? "#Color" : "#Black&White");

  return 0;
}