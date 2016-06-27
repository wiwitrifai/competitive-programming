#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int l[N], n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", l+i);
  sort(l, l+n);
  int low = l[n-1]-l[0]+1, hi = l[0] + l[1]-1;
  puts((low <= hi) ? "YES" : "NO");
  if(low <= hi)
    printf("%d\n", low);

  return 0;
}