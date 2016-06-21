#include <bits/stdc++.h>

using namespace std;
const int N = 10005;
int n;
long long a[N], b[N];
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%I64d", a+i);
  for(int i = 0; i<n; i++)
    scanf*"%I64d", b+i);
  sort(a, a+n);
  sort(b, b+n);
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    long long tmp = a[i]-b[i];
    if(tmp < 0)
      tmp = -tmp;
    ans += tmp;
  }
  cout << ans << endl;

  return 0;
}