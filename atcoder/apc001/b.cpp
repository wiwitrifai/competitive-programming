#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  long long bisa = 0, need = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] > a[i])
      need += b[i]-a[i];
    else
      bisa += (a[i] - b[i])/2;
  }
  puts((need <= bisa) ? "Yes" : "No");
  return 0;
}