#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long all = 1, odd = 1;
  for (int i = 0; i < n; i++) {
    all *= 3;
    int a;
    scanf("%d", &a);
    if ((a & 1) == 0)
      odd *= 2;
  }
  cout << all - odd << endl;
  return 0;
}