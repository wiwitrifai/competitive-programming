#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

void win() {
  puts("sjfnb");
  exit(0);
}

void lose() {
  puts("cslnb");
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int cnt = 0;
  for (int i = 0; i+1 < n; ++i) {
    cnt += a[i] == a[i+1];
  }
  if (cnt > 1) {
    lose();
  }
  if (n == 1) {
    if (a[0] & 1)
      win();
    else
      lose();
  }
  if (cnt == 1) {
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i] == a[i+1]) {
        if (a[i] == 0)
          lose();
        if (i > 0 && a[i-1] + 1 == a[i]) {
          lose();
        }
      }
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  long long tot = 1LL * n * (n-1) / 2;
  long long sisa = sum - tot;
  if (sisa & 1) {
    win();
  }
  else {
    lose();
  }
  return 0;
}
