#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 0; i<n; i++)
      scanf("%d", b+i), sum += b[i];
    for(int i = 0; i<n; i++)
      scanf("%d", a+i), sum += a[i];
    int avg = sum / n;
    if(sum % n) {
      puts("-1");
      continue;
    }
    bool ok = true;
    for(int i = 0; i<n; i++) {
      // cerr << i << " " << a[i] << " " << b[i] <<  endl;
      if(a[i] > avg) {
        ok = false;
        break;
      }
      if((a[i]+b[i]) == avg)
        continue;
      if(i == n-1) {
        ok = false;
        break;
      }
      // cerr << a[i] << " " << b[i+1] << " h " << avg << endl;
      if(a[i] == avg) {
        a[i+1] += b[i];
      }
      else if((a[i] + b[i+1]) == avg ) {
        a[i+1] += b[i];
        b[i+1] = 0;
      }
      else {
        a[i] += b[i] + b[i+1];
        b[i+1] = 0;
        if(a[i] != avg) {
          ok = false;
          break;
        }
      }
    }
    printf("%d\n", ok ? avg : -1);
  }

  return 0;
}