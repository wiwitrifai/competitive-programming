#include <bits/stdc++.h>

using namespace std;

int c[55];
int n;
long long get(long long l) {
  long long ans = 0, cur = c[0];
  for (int i = 0; l; ++i, l >>= 1) {
    if (i < n)
      cur = min(cur, (long long)c[i]);
    if (l & 1)
      ans += cur;
    cur <<= 1;
  }
  return ans;
}

int main() {
  long long l;
  cin >> n >> l;
  for (int i = 0; i < n; ++i)
    scanf("%d", c+i);
  long long ans = get(l);
  for (int i = 0; i < 31 && l <= (1LL << 30); ++i, l += l & -l) {
    ans = min(ans, get(l));
  }  
  cout << ans << endl;
  return 0;
}