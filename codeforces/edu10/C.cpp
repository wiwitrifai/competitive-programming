#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, m;
int p[N], last[N], pos[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i<=n; i++) {
    scanf("%d", p+i);
    pos[p[i]] = i;
    last[i] = n;
  }
  while(m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = pos[l]; r = pos[r];
    if(l > r)
      swap(l, r);
    last[l] = min(r-1, last[l]);
  }
  int now = n;
  long long ans = 0;
  for(int i = n; i>=1; i--) {
    now = min(now, last[i]);
    ans += now-i+1;
  }
  cout << ans << endl;
  return 0;
}