#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = k * 1900 + (n-k) *100;
  for (int i = 0; i < k; i++)
    ans <<= 1;
  cout << ans << endl;
  return 0;
}