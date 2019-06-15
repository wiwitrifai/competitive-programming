#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    puts("0");
    return 0;
  }
  int low = 1, high = n - (k-1);
  printf("%d\n",high - low);
  return 0;
}
