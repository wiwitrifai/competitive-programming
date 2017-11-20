#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  int l = 0, r = 0;
  for (int i =0; i < n; i++)
    scanf("%d", a+i), r = max(r, a[i]);
  while (l < r) {
    int mid = (l + r + 1)>> 1;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += a[i] / mid;
    }
    if (cnt >= k)
      l = mid;
    else
      r = mid-1;
  }
  cout << l << endl;
  return 0;
}