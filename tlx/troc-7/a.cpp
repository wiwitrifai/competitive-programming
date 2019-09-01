#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  long long suma = 0, sumb = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    suma += a[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    sumb += b[i];
  }
  if (sumb - suma <= 1) {
    puts("-1");
    return 0;
  }
  bool ada = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    if (a[i] < b[i] && !ada) {
      ada = 1;
      x = a[i]+1;
    }
    printf("%d%c", x, i+1 == n ? '\n' : ' ');
  }
  return 0;
}
