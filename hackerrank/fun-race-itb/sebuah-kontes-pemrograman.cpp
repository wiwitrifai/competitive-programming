#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6;

int n, q;
pair< int, int > a[N];

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    a[i] = {-s, t};
  } 
  sort(a, a+n);
  while (q--) {
    int k;
    scanf("%d", &k);
    if (k > n)
      puts("0");
    else {
      k--;
      int ans = upper_bound(a, a+n, a[k]) - lower_bound(a, a+n, a[k]);
      printf("%d\n", ans);
    }
  }

  return 0;
}