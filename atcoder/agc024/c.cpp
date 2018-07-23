#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

void die() {
  puts("-1");
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  if (a[0] != 0) die();
  int last = 0;
  long long ans = 0;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] < last -1) die();
    else if (a[i] == last-1) {
    }
    else
      ans += a[i];
    last = a[i];
  }
  cout << ans << endl;
  return 0;
}