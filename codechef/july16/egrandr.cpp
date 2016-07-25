#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    int sum = 0, x;
    bool fail = false, full = false;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      scanf("%d", &x);
      sum += x;
      if(x == 2)
        fail = true;
      if(x == 5)
        full = true;
    }
    puts(!fail && full && (sum/n >= 4) ? "Yes" : "No");
  }

  return 0;
}