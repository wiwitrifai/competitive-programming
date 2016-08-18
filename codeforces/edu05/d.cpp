#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], n, k;
int used[N];

int main() {
  scanf("%d%d", &n, &k);
  int l, r, last, now;
  l = r = 1;
  last = now = 0;
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    used[a[i]]++;
    if(used[a[i]] == 1)
      now++;
    while(now > k) {
      used[a[last]]--;
      if(used[a[last]] == 0)
        now--;
      last++;
    }
    if(r-l < i-last) {
      l = last+1;
      r = i+1;
    }
  }
  printf("%d %d\n", l, r);
  return 0;
}