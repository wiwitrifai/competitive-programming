#include <bits/stdc++.h>

using namespace std;

long long beg[5][22][9][4][8][10], dp[22][9][4][8][10];
int val[] = {3, 5, 7, 9}, mark[] = {1, 0, 2, 4};

long long get(long long n) {
  stack< int > st;
  long long cur = n, mul = 1;
  while (cur) {
    st.push(cur % 10);
    cur /= 10;
    mul *= 10;
  }
  long long ret = 0;
  for (int i = 0; i + 1 < st.size(); i++) {
    for (int mask = 0; mask < 8; mask++) {
      for (int r3 = 0; r3 < 3; r3++) {
        if (r3 == 0 && (mask & 1)) continue; 
        for (int r7 = 0; r7 < 7; r7++) {
          if (r7 == 0 && (mask & 2)) continue; 
          for (int r9 = 0; r9 < 9; r9++) {
            if (r9 == 0 && (mask & 4)) continue; 
            ret += dp[i][mask][r3][r7][r9];
          }
        }
      }
    }
  }
  cur = 0;
  bool ok = 1;
  int cmask = 0;
  while (!st.empty() && ok) {
    int now = st.top(); st.pop();
    ok = 0;
    for (int c = 0; c < 4; c++) {
      if (val[c] == now) {
        ok = 1;
        break;
      }
      else if (val[c] > now)
        break;
      for (int mask = 0; mask < 8; mask++) {
        int bmask = mask | cmask;
        for (int r3 = 0; r3 < 3; r3++) {
          if (((cur+r3) % 3) == 0 && (bmask & 1)) continue; 
          for (int r7 = 0; r7 < 7; r7++) {
            if (((cur+r7) % 7) == 0 && (bmask & 2)) continue; 
            for (int r9 = 0; r9 < 9; r9++) {
              if (((cur+r9) % 9) == 0 && (bmask & 4)) continue; 
              // if (beg[c][st.size()][mask][r3][r7][r9])
              // cerr << val[c] << " " << st.size() << " " << mask << " " << r3 << " " << r7 << " " << r9 << " = " << beg[c][st.size()][mask][r3][r7][r9] << endl;
              ret += beg[c][st.size()][mask][r3][r7][r9];
            }
          }
        }
      }
    }
    mul /= 10;
    cur += mul * now;
    for (int i = 0; i < 4; i++)
      if (now == val[i])
        cmask |= mark[i];
    // cerr << n << " " <<  cur << endl;
  }
  return ret;
}

int main() {
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < 4; i++) {
    if (val[i] == 5) continue;
    beg[i][0][mark[i]][val[i] % 3][val[i] % 7][val[i] % 9]++;
    dp[0][mark[i]][val[i] % 3][val[i] % 7][val[i] % 9]++;
  }
  long long mul = 1;
  for (int i = 0; i < 20; i++) {
    mul *= 10;
    for (int mask = 0; mask < 8; mask++) {
      for (int r3 = 0; r3 < 3; r3++) {
        for (int r7 = 0; r7 < 7; r7++) {
          for (int r9 = 0; r9 < 9; r9++) {
            if (dp[i][mask][r3][r7][r9] == 0) continue;
            for (int c = 0; c < 4; c++) {
              long long cur = mul * val[c];
              int nmask = mask | mark[c], nr3 = (cur + r3) % 3, nr7 = (cur + r7) % 7, nr9 = (cur + r9) % 9;
              dp[i+1][nmask][nr3][nr7][nr9] += dp[i][mask][r3][r7][r9];
              beg[c][i+1][nmask][nr3][nr7][nr9] += dp[i][mask][r3][r7][r9];
            }
          }
        }
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    long long a, b, k;
    scanf("%lld %lld %lld", &a, &b, &k);
    a++, b++;
    long long ca = get(a-1), cb = get(b);
    if (ca + k > cb)
      puts("-1");
    else {
      ca += k;
      while (a < b) {
        long long mid = (a + b) >> 1;
        if (get(mid) >= ca)
          b = mid;
        else
          a = mid+1;
      }
      printf("%lld\n", a-1);
    }
  }
  return 0;
}