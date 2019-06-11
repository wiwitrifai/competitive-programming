#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bool nonprime[N];
vector<int> prime;
pair<int, int> goldbach[N];
int dp[N];

int main() {
  for (int i = 2; i < N; ++i) {
    if (nonprime[i]) continue;
    prime.push_back(i);
    for (int j = i + i; j < N; j += i)
      nonprime[j] = 1;
  }
  for (int i = 4; i < N; i += 2) {
    for (int p : prime) {
      int x = i - p;
      if (!nonprime[x]) {
        goldbach[i] = {p, x};
        break;
      }
    }
  }
  for (int i = 4; i < N; i += 2) {
    dp[i] = dp[goldbach[i].second - goldbach[i].first] + 1;
  }
  int n;
  scanf("%d", &n);
  printf("%d\n", dp[n]);
  return 0;
}
