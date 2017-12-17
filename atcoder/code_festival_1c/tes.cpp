#include <bits/stdc++.h>

using namespace std;

int main() {
  static int a = 5;
  printf("%d", a--);
  if (a)
    main();
  return 0;
}