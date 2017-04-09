#include <bits/stdc++.h>

using namespace std;

int val[11];

int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    printf("Case #%d: ", tc);
    int n;
    scanf("%d", &n);
    long long now = n;
    memset(val, 1, sizeof val);
    if(n == 0) {
      puts("INSOMNIA");
      continue;
    }
    int cnt = 0;
    while(cnt < 10) {
      long long ha = now;
      while(ha) {
        int x = ha % 10;
        ha /= 10;
        if(val[x]) {
          cnt++;
          val[x] = 0;
        }
      }
      if(cnt < 10)
        now += n;
    }
    cerr << "TC #" << tc << "\n";
    printf("%lld\n", now);
  }
  return 0;
}