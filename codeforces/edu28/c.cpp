#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), sum += a[i];
  long long ans = 0;
  long long cur = 0;
  int le = 0, mid = 0, ri = 0;
  for (int i = 0; i < n; i++) {
    cur += a[i];
    long long now = 0;
    if (ans < cur) {
      le = mid = ri = i+1;
      ans = cur;
    }
    // cerr << i+1 << " " << i+1 << " "<< i+1 << " " << 2 * cur - sum << endl;
    int ll = 0;
    for (int j = 0; j <= i; j++) {
      now += a[j];
      if (now > 0) {
        now = 0;
        ll = j+1;
      }
      // cerr << ll << " " << j+1 << " " << i+1 << " " << 2 * (cur - now) - sum << endl;
      if (ans < cur - now) {
        ans = cur - now;
        le = ll;
        mid = j+1;
        ri = i+1;
      }
    }
  }
  // cerr << ans * 2 - sum << endl;
  printf("%d %d %d\n", le, mid, ri);
  return 0;
}