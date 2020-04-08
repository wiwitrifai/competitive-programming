#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int prime[N];

int main() {
  for (int i = 2; i < N; ++i) {
    if (prime[i]) continue;
    for (int j = i; j < N; j += i) {
      if (prime[j]) continue;
      prime[j] = i;
    }
  }
  int n;
  scanf("%d", &n);
  vector<int> val(n);
  val[0] = 1;
  for (int i = 2; i <= n; ++i) {
    val[i-1] = i / prime[i];
  }
  sort(val.begin(), val.end());
  for (int i = 1; i < n; ++i) {
    printf("%d%c", val[i], i+1 == n ? '\n' : ' ');
  }
  return 0;
}
