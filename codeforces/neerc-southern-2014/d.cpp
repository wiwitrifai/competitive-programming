#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair< ll, int > li;
typedef pair< int, int > ii;
typedef pair< li, ii > liii;

#define FF first
#define SS second
#define mp make_pair

int main()
{
  int i, j, r, w;
  ll n, m, sum;
  vector < liii > ser;
  cin >> n >> m;
  ser.assign(n, liii());
  for(i= 0; i<n; i++)
  {
    cin >> ser[i].FF.FF >> ser[i].FF.SS;
    ser[i].SS.SS = 0;
    ser[i].SS.FF = i+1;
  }
  sort(ser.begin(), ser.end());
  r = w = 0;
  sum = 0;
  for(i=n-1; i>=0; i--)
  if(sum<m)
  {
    r++;
    sum += ser[i].FF.FF;
    w += ser[i].FF.SS;
    ser[i].SS.SS = 1;
  }
  else
    break;
  
  j = i+1;
  while(j<n && i>=0)
  {
    while(ser[j].FF.SS)
      j++;
    while(i<n)
      if(ser[i].FF.SS == 0)
        i--;
      else
        break;
    if(i>=0 && j<n)
      if(sum-ser[j].FF.FF+ser[i].FF.FF>=m)
      {
        sum = sum-ser[j].FF.FF+ser[i].FF.FF;
        w++;
        ser[j].SS.SS = 0;
        ser[i].SS.SS = 1;
        i--;
        j++;
      }
      else
        break;
  }
  printf("%d %d\n", r, w);
  for(i= j = 0; i<n; i++)
    if(ser[i].SS.SS)
      printf("%s%d", j++ ? " ": "", ser[i].SS.FF);
  printf("\n");
  return 0;
}