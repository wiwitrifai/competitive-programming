#include <bits/stdc++.h>

using namespace std;

vector<long long> solve(long long a, long long b, long long m) {
  for (int len = 1; ; ++len) {
    long long low = a, slow = a, high = a, shigh = a;
    for (int i = 1; i < len; ++i) {
      low = slow + 1;
      high = shigh + m;
      slow += low;
      shigh += high;
    }
    if (b < low) break;
    if (b > high) continue;
    long long sisa = b - low;
    vector<long long> ans;
    ans.push_back(a);
    long long sum = a;
    for (int i = 2; i <= len; ++i) {
      int jarak = len-i;
      long long cost = jarak <= 1 ? 1 : (1LL << (jarak-1));
      long long r = min(m-1, sisa/cost) + 1;
      sisa -= cost * (r-1);
      long long cur = sum + r;
      sum += cur;
      ans.push_back(cur);
    }
    assert(ans.back() == b);
    return ans;
  }
  return vector<long long>();
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long a, b, m;
    scanf("%lld %lld %lld", &a, &b, &m);
    vector<long long> ans = solve(a, b, m);
    if (ans.empty())
      puts("-1");
    else {
      printf("%d", (int)ans.size());
      for (long long x : ans) {
        printf(" %lld", x);
      }
      printf("\n");
    }
  }
  return 0;
}
