#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, x;
    long long m;
    scanf("%d %d %lld %d", &n, &k, &m, &x);
    if (k == 1) {
      puts((long long)n == m ? "yes" : "no");
      continue;
    }
    vector<int> pw;
    while (m > 0) {
      pw.push_back(m % k);
      m /= k;
    }
    if (k >= 3) {
      int cnt = 0;
      bool ok = pw[0] <= 1;
      for (int u : pw) {
        cnt += u;
        ok &= u <= 2;
      }
      ok &= cnt == n;
      puts(ok ? "yes" : "no");
      continue;
    }
    else {
      int cnt = 0;
      for (int u : pw)
        cnt += u;
      if (cnt > n) {
        puts("no");
        continue;
      }
      for (int i = 1; i + 1 < pw.size() && cnt < n; ++i) {
        if (pw[i] == 0 && pw[i+1] > 0) {
          ++cnt;
          pw[i] = 2;
          --pw[i+1];
        }
      }
      int add = 0;
      bool can = 0;
      for (int i = (int)pw.size()-1; i > 0; --i) {
        if (pw[i] == 2)
          can = 1;
        else if (pw[i] == 1)
          can = 0;
        else {
          assert(pw[i] == 0);
          if (can)
            ++add;
        }
      }
      if (cnt <= n && cnt + add >= n) {
        puts("yes");
      }
      else {
        puts("no");
      }
    }
  }
  return 0;
}
