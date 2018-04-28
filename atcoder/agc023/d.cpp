#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int x[N], p[N], n, s;

int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", x+i, p+i);
  }
  if (s < x[0]) {
    printf("%lld\n", abs(x[n-1] - s));
    return 0;
  }
  if (x[n-1] < s) {
    printf("%lld\n", abs(x[0] - s));
    return 0;
  }
  int l = 0, r = n-1;
  bool left = p[l] < p[r];
  long long sudah = 0;
  long long ans = 0;
  int last = s;
  if (left) sudah += p[l], last = x[l], ++l;
  else sudah += p[r], last = x[r], --r;
  while (l < r && x[l] < s && x[r] > s) {
    bool pilih = left;
    if (left) {
      pilih = ((sudah + p[r]) > p[l]);
    }
    else {
      pilih = ((sudah + p[l]) < p[r]);
    }
    if (pilih) {
      ans += abs(x[l] - last);
      last = x[l];
      sudah += p[l];
      ++l;
    }
    else {
      ans += abs(x[r] - last);
      last = x[r];
      sudah += p[r];
      --r;
    }
    left = pilih;
  }
  if (x[l] > s) {
    ans += abs(x[r] - s);
    ans += abs(x[r] - last);
  }
  else {
    ans += abs(x[l] - s);
    ans += abs(x[l] - last);
  }
  cout << ans << endl;
  return 0;
}