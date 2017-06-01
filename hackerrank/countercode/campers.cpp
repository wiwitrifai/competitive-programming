#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+5;

int n, k, id[N];

int main() {
  scanf("%d%d", &n, &k);
  for(int i =0; i<k; i++)
    scanf("%d", id+i);
  sort(id, id+k);
  int now = 0;
  int ans = k;
  for(int i = 0; i<k; i++) {
    ans += (id[i]-now-1)/2;
    now = id[i]+1;
  }
  ans += (n-now+1)/2;
  printf("%d\n", ans);
  return 0;
}