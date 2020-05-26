#include <bits/stdc++.h>

using namespace std;

const int S = 2e5;

int main() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &b[i]);
  long long tota = 0, totb = 0;
  for (int i = 0; i < n; ++i) {
    tota += a[i];
    totb += b[i];
  }
  vector<long long> ans;
  bool ok = true;
  if (n >= 4) {
    while (ok && totb > tota) {
      if (b[0] > b.back()) {
        ans.emplace_back(-1);
        reverse(b.begin(), b.end());
      }
      ans.emplace_back(1);
      totb = b[0];
      for (int i = n-1; i > 0; --i) {
        b[i] -= b[i-1];
        totb += b[i];
        ok &= b[i] > 0;
      }
    }
  } else if (n == 2) {
    long long maxi = max(a[0], a[1]);
    while (ok && totb > tota) {
      if (b[0] > b.back()) {
        ans.emplace_back(-1);
        reverse(b.begin(), b.end());
      }
      b[1] -= b[0];
      long long k = max(b[1] - maxi, 0LL) / b[0];
      ans.emplace_back(1 + k);
      b[1] -= k * b[0];

      if (max(b[0], b[1]) < maxi) {
        ok = false;
        break;
      }

      totb = 0;
      for (int i = 0; i < n; ++i) {
        totb += b[i];
        ok &= b[i] > 0;
      }
    }
  } else if (n == 3) {
    long long maxi = max(a[0], a[2]);
    while (ok && totb > tota) {
      if (b[0] > b.back()) {
        ans.emplace_back(-1);
        reverse(b.begin(), b.end());
      }
      for (int i = n-1; i > 0; --i) {
        b[i] -= b[i-1];
        ok &= b[i] > 0;
      }

      if (!ok) break;

      long long k = max(b[1] - a[1], 0LL) / b[0];
      long long lo = 0, hi = k;
      while (lo < hi) {
        long long mid = (lo + hi + 1) >> 1;
        long long sum = mid * (b[1] + b[1] - b[0] * (mid-1)) / 2;
        long long b1 = b[1] - mid * b[0], b2 = b[2] - sum;
        if (b2 >= maxi && b1 >= a[1] && b[0] + b1 + b2 >= tota)
          lo = mid;
        else
          hi = mid - 1;
      }
      b[2] -= lo * (b[1] + b[1] - b[0] * (lo-1)) / 2;
      b[1] -= b[0] * lo;
      ans.emplace_back(1 + lo);
      if (max(b[0], b[2]) < maxi) {
        ok = false;
        break;
      }

      totb = 0;
      for (int i = 0; i < n; ++i) {
        totb += b[i];
        ok &= b[i] > 0;
      }
    }
  }
  if (!ok || tota != totb) {
    puts("IMPOSSIBLE");
    return 0;
  }
  if (a != b) {
    ans.emplace_back(-1);
    reverse(b.begin(), b.end());
  }
  if (a != b) {
    puts("IMPOSSIBLE");
  } else {
    reverse(ans.begin(), ans.end());
    long long cnt = 0, r = 0;
    for (auto x : ans) {
      if (x < 0) {
        ++r;
        continue;
      }
      cnt += x;
    }
    if (cnt > S) {
      puts("BIG");
      printf("%lld\n", cnt);
    } else {
      puts("SMALL");
      printf("%lld\n", cnt + r);
      for (auto x : ans) {
        if (x < 0) {
          printf("R");
          continue;
        }
        for (int i = 0; i < x; ++i)
          printf("P");
      }
      printf("\n");
    }
  }
  return 0;
}
