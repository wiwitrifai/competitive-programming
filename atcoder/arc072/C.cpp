#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  long long ans1 = 0, ans2 = 0;
  long long now1 = 0, now2 = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    now1 += a[i];
    now2 += a[i];
    if (i & 1) {
      if (now1 <= 0) {
        ans1 += 1 - now1;
        now1 = 1;
      }
      if (now2 >= 0) {
        ans2 += now2 + 1;
        now2 = -1;
      }
    }
    else {
      if (now1 >= 0) {
        ans1 += now1+1;
        now1 = -1;
      }
      if (now2 <= 0) {
        ans2 += 1 - now2;
        now2 = 1;
      }
    }
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}