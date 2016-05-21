#include <bits/stdc++.h>

using namespace std;

char test[60];

const int N = 1e6 + 6;

int n, a[N], b[N];

int main() {
  scanf("%s", test);
  scanf("%d", &n);
  int ma = 0;
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    ma = max(ma, a[i]);
    b[i] = 32 - __builtin_clz(a[i]);
    if((a[i] & (a[i]-1)) == 0)
      b[i]--;
    ans += (1LL<<b[i]) - a[i];
    cerr << i << ' ' << a[i] << endl;
  } 
  cerr << ans << " " << 1 << endl;
  int sol = 1;
  for(int i = 2; i<= ma; i++) {
    int bb = 32 - __builtin_clz(i);
    long long temp = 0;
    for(int j = 0; j < n; j++) {
      long long now = i;
      while(now < a[j]) {
        now <<= 1;
      }
      temp += now - a[j];
    }
    // cerr << temp << " " << i << endl;
    if(ans > temp) {
      ans = temp;
      sol = i;
    }
  }
  cout << ans << " " << sol << endl;

  return 0;
}