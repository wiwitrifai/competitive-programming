#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    unsigned long long n, m;
    cin >> n >> m;
    if (n >= m)
      puts("0");
    else {
      unsigned long long ans = 1;
      for (int i = 1; i <= n; i++) {
        ans = (ans * i) % m;
      } 
      cout << ans << endl;
    }
  }
  return 0;
}