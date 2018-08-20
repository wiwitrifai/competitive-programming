#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], b[N];

int main() {
  vector<int> prime;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a+i, b+i);
  }
  long long now = a[0];
  for (long long i = 2; i * i <= now; ++i) {
    if (now % i) continue;
    prime.push_back(i);
    while ((now % i) == 0) {
      now /= i;
    }
  }
  if (now > 1)
    prime.push_back(now);
  now = b[0];
  for (long long i = 2; i * i <= now; ++i) {
    if (now % i) continue;
    prime.push_back(i);
    while ((now % i) == 0) {
      now /= i;
    }
  }
  if (now > 1)
    prime.push_back(now);
  sort(prime.begin(), prime.end());
  prime.erase(unique(prime.begin(), prime.end()), prime.end());
  int ans = -1;
  for (int p : prime) {
    ans = p;
    for (int i = 0; i < n; ++i) {
      if ((a[i] % p) && (b[i] % p)) {
        ans = -1;
        break;
      }
    }
    if (ans != -1)
      break;
  }
  printf("%d\n", ans);
  return 0;
}