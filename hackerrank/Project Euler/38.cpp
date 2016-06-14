#include <bits/stdc++.h>

using namespace std;

bool ok[10];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);  
  for(int i = 2; i<=n; i++) {
    memset(ok, false, sizeof ok);
    int cnt = 0;
    bool pan = true;
    for(int j = 1; j<9 && (cnt < k) && pan; j++) {
      int now = i * j;
      while(now && pan) {
        int r = now % 10;
        if(r < 1 || r > k || ok[r])
          pan = false;
        ok[r] = true;
        now /= 10;
        cnt++;
      }
    }
    if(pan)
      printf("%d\n", i);
  }
  return 0;
}