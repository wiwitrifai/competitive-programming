#include <bits/stdc++.h>

using namespace std;

const int N = 2024, mod = 1e9 + 7;

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

int n;
int dp[N][N][2];

int get(int len, int sum, int last) {
  if (len == n) {
    assert(sum == 0);
    return 0;
  }
  int & ret = dp[len][sum][last];
  if (ret != -1)
    return ret;
  ret = 0;
  bool atas = (sum + 1 - (n - len - 1)) <= 0;
  bool bawah = sum > 0;
  if (atas && bawah) {
    ret = last;
    add(ret, get(len+1, sum+1, !last));
    add(ret, get(len+1, sum-1, 1));
    int oth = last;
    add(oth, get(len+1, sum+1, 1));
    add(oth, get(len+1, sum-1, !last));
    assert(oth == ret);
  }
  else if (atas) {
    ret = last;
    add(ret, get(len+1, sum+1, !last));
  }
  else if (bawah) {
    ret = last;
    add(ret, get(len+1, sum-1, !last));
  }
  else {
    assert(false);
  }
  return ret;
}


int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  n *= 2;
  int ans = get(0, 0, 1);
  printf("%d\n", ans);
  return 0;
}
