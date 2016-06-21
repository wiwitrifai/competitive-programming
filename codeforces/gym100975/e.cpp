#include <bits/stdc++.h>

using namespace std;
const int N = 4e3 + 5, M = 15e6 + 6;
int cnt[M<<2], a[N], n;
int main() {
  freopen("abc.in", "r", stdin);
  freopen("abc.out", "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    cnt[a[i]+M]++;
  }
  long long ans = 0;
  for(int i = 0; i<n; i++)
    for(int j = i+1; j<n; j++) {
      int sum = a[i]+a[j];
      if(sum + M < 0 || sum >= M)
        continue;
      int now = cnt[sum+M];
      if(a[i] == sum)
        now--;
      if(a[j] == sum)
        now--;
      ans += now*2;
    }
  cout << ans << endl;

  return 0;
}