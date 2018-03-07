#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
int main()
{
  int n, k, x;
  ll a[200005], sum, mi, ans = 0, y;
  scanf("%d%d", &n, &k);
  mi = 1000;
  for(int i=0; i<n; i++)
  {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  sum = 0;
  for(int i = 0; i<k; i++)
    sum += a[i];
  if(sum>=0)
      ans += sum + 1;
  x = k-1;
  while(sum>=0)
    if(a[x]-mi <= sum+1)
    {
      sum -= (a[x]-mi);
      a[x] = mi;
      x--;
    }
    else
    {
      a[x] -= (sum+1);
      sum = -1;
      break;
    }
  for(int i=k; i<n; i++)
  {
    sum = sum-a[i-k]+a[i];
    if(sum>=0)
      ans += sum + 1;
    x = i;
    while(sum>=0)
      if(a[x]-mi <= sum+1)
      {
        sum -= (a[x]-mi);
        a[x] = mi;
        x--;
      }
      else
      {
        a[x] -= (sum+1);
        sum = -1;
        break;
      }
  }
  cout << ans << '\n';
  cout << a[0];
  for(int i=1; i<n; i++)
    cout << ' ' << a[i];
  cout << '\n';
  return 0;
}