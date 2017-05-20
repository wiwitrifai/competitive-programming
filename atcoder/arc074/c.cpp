#include <bits/stdc++.h>

using namespace std;

int main() {
  long long h, w;
  cin >> h >> w;
  long long ans = h * w;
  if ((h % 3) == 0)
    ans = 0;
  else
    ans = min(ans, w);
  if ((w % 3) == 0)
    ans = 0;
  else
    ans = min(ans, h);
  for (long long i = 1; i < h; i++) {
    long long ma = i * w, mi = i * w;
    long long a = ((w)/2) * (h-i), b = ((w+1)/2) * (h-i);
    ma = max(ma, b);
    mi = min(mi, a);
    ans = min(ans, ma-mi);
  }
  swap(w, h);
  for (long long i = 1; i < h; i++) {
    long long ma = i * w, mi = i * w;
    long long a = ((w)/2) * (h-i), b = ((w+1)/2) * (h-i);
    ma = max(ma, b);
    mi = min(mi, a);
    ans = min(ans, ma-mi);
  }
  cout << ans << endl;
  return 0;
}