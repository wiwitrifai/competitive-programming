#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  int mn = a[0];
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += a[i] > mn;
  puts(cnt < n/2 ? "Bob" : "Alice");
  return 0;
}
