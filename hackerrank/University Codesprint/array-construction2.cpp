#include <bits/stdc++.h>

using namespace std;
const int N = 55;
int a[N], n;
bool solve(int i, int s, int k) {
  if (i == n) {
    if (s || k)
      return false;
    return true;
  }
  for (int j = 0; j <= s; j++) {
    a[i] = j;
    int m = 0;
    for (int z = 0; z < i; z++)
      m += abs(j-a[z]);
    if (m <= k)
      if(solve(i+1, s-j, k-m))
        return true;
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int s, k;
    scanf("%d %d %d", &n, &s, &k);
    if (!solve(0, s, k))
      puts("-1");
    else {
      for (int i = 0; i < n; i++)
        printf("%d%c", a[i], (i==n-1) ? '\n' : ' ');
    }
  }
  return 0;
}