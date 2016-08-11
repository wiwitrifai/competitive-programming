#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int la = 0, l = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for(int i = 0; i<n; i++) {
    if(a[i] == 0) {
      if(k)
        k--;
      else {
        while(l <= i && a[l] == 1) l++;
        l++;
      }
    }
    if(ans < i-l+1) {
      ans = i-l+1;
      la  = l;
    }
  }
  printf("%d\n", ans);
  for(int i = 0; i< ans; i++)
    a[la+i] = 1;
  for(int i = 0; i<n; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}