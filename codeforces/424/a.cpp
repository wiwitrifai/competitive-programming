#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

long long a[N], b[N];
int p, n, k;

bool can(long long lim) {
  for (int i = 0, j = 0; i < n; i++, j++) {
    while (j < k && (abs(b[j]-p) + abs(b[j]-a[i])) > lim) j++;
    if (j == k) return false;
  }
  return true;
}

int main() {
  scanf("%d %d %d", &n, &k, &p); 
  for (int i = 0; i < n; i++) {
    scanf("%I64d", a+i);
  } 
  for (int i = 0; i < k; i++) {
    scanf("%I64d", b+i);
  }
  sort(a, a+n);
  sort(b, b+k);
  long long le = 0, ri = 1e12;
  while (le < ri) {
    long long mid = (le + ri) >> 1;
    if (can(mid))
      ri = mid;
    else
      le = mid + 1;
  }
  cout << le << endl;

  return 0;
}