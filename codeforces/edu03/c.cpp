#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
  scanf("%d", &n);
  long long sum = 0;
  for(int i = 0; i<n; i++)
    scanf("%d", a+i), sum += a[i];
  sort(a, a+n);
  int low = sum/n, up = (sum + n-1)/n, nup = sum % n, nlow = n - nup;
  long long ans = 0;
  for(int i = 0; i<nlow; i++) {
    ans += abs(low - a[i]);
  }
  for(int i = 0; i<nup; i++)
    ans += abs(up - a[i+nlow]);
  ans >>= 1;
  cout << ans << endl;

  return 0;
}