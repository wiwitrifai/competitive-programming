#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
const long long B = 1e9;

vector<long long > ans[N];

int main() {
  ans[1] = {1};
  for (int i = 2; i < N; i++) {
    long long mul = i - (i-1)/2, cur = 0;
    for (long long x : ans[i-1]) {
      cur += x * mul;
      ans[i].push_back(cur % B);
      cur /= B;
    }
    while (cur) {
      ans[i].push_back(cur);
      cur /= B;
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld", ans[n].back());
    for (int i = (int)ans[n].size()-2; i >= 0; i--) {
      printf("%09lld", ans[n][i]);
    }
    printf("\n");
  }

  return 0;
}