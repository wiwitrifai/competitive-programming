#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N], b[N];

int main() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a+i);
    sum += a[i];
  }
  long long con = 1LL * n * (n + 1)/2;
  if (sum % con) {
    puts("NO");
    return 0;
  }
  long long cur = sum/con;
  bool ok = 1;
  for (int i = 0; i < n; i++)
    if (a[i] < cur)
      ok = 0;
  if (!ok) {
    puts("NO");
    return 0;
  }
  a[n] = a[0];
  long long all = 0;
  for (int i = 0; i < n; i++) {
    long long diff = a[i+1] - a[i] - cur;
    diff *= -1;
    if (diff < 0) {
      puts("NO");
      return 0;
    }
    if (diff % n) {
      puts("NO");
      return 0;
    }
    all += diff/n;
  } 
  if (all != cur) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}