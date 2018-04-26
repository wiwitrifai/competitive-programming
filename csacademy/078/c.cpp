#include <bits/stdc++.h>

using namespace std;

int banned[10];
long long n;
int d[50];


int main() {
  for (int i = 0; i < 10; ++i)
    scanf("%d", banned+i);
  scanf("%lld", &n);
  int k = 0;
  while (n) {
    d[k++] = n % 10;
    n /= 10;
  }
  long long cnt = 0;
  for (int i = 0; i < 10; ++i) {
    cnt += !banned[i];
  }
  if (k == 1) {
    int ans = 0;
    for (int i = 0; i < d[0]; ++i) {
      ans += !banned[i];
    }
    cout << ans << endl;
    return 0;
  }
  long long ans = 0, cur = cnt, awal = cnt;
  if (!banned[0]) --awal;
  ans += cur;
  for (int i = 2; i < k; ++i) {
    awal *= cnt;
    ans += awal;
  } 
  // cerr << ans << endl;
  long long val = 1;
  for (int i = 1; i < k; ++i)
    val *= cnt;
  reverse(d, d+k);
  for (int i = 0; i < k; ++i) {
    for (int now = (i == 0); now < d[i]; ++now) {
      if (banned[now]) continue;
      ans += val;
      // cerr << i << " " << now << " " << val << endl;
    } 
    val /= cnt;
  }
  cout << ans << endl;
  return 0;
}