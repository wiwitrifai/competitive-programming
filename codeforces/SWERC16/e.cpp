#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 3;
const int N = 25;

int dp[N][8];
int num[N];
bool ampas[N];
char s[N * N][N];

long long del[N][8];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

int main() {
  int A, B, n; 
  scanf("%d %d %d", &A, &B, &n);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    if (ampas[i]) continue;
    for (int j = 0; j < n; j++) {
      if (i == j || ampas[j]) continue;
      int li = strlen(s[i]);
      int lj = strlen(s[j]);
      for (int st = 0; st + lj <= li; st++) {
        bool same = 1;
        for (int k = 0; k < lj; k++) {
          if (s[i][st + k] != s[j][k]) {
            same = 0;
            break;
          }
        }
        if (same) {
          ampas[i] = 1;
          goto HELL;
        }
      }
    }
    HELL:;
  }
  for (int i = 0; i < n; i++) printf("%d ", ampas[i]); printf("\n");
  for (int i = 0; i < n; i++) {
    if (ampas[i]) continue;
    long long now = 1;
    int len = strlen(s[i]);
    string str = "oiest";
    int b = 0;
    for (int j = 0; j < len; j++) {
      bool ada = 0;
      for (int k = 0; k < str.size(); k++) {
        if (s[i][j] == str[k]) {
          ada = 1;
          break;
        }
      }
      if (ada) {
        b++;
        now = now * 3 % mod;
      } else {
        now = now * 2 % mod;
      }
    }
    long long add[8] = {};
    add[1] = 1;
    add[2] = 1;
    add[4] = (b == len);
    add[3] = power(2, len) - 2;
    add[6] = power(2, b) - 1;
    add[5] = power(2, b) - 1;
    add[7] = now;
    for (int j = 0; j <= 6; j++) {
      add[7] -= add[j];
      add[7] %= mod;
      if (add[7] < 0) add[7] += mod;
      add[j] %= mod;
      if (add[j] < 0) add[j] += mod;
    }
    for (int j = 0; j < 8; j++) {
      del[len][j] += add[j];
      del[len][j] %= mod;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= B; i++) {
    for (int mask = 0; mask < 8; mask++) {
      dp[i][mask | 1] += dp[i-1][mask] * 26;
      dp[i][mask | 2] += dp[i-1][mask] * 26;
      dp[i][mask | 4] += dp[i-1][mask] * 10;
    }
    for (int j = 0; j < 8; j++) {
      dp[i][j] %= mod;
    }
    for (int j = 1; j <= i; j++) {
      for (int mask = 0; mask < 8; mask++) {
        for (int bef = 0; bef < 8; bef++) {
          int& cur = dp[i][bef|mask];
          cur -= dp[i-j][bef] * del[j][mask];
          cur %= mod;
          if (cur < 0) cur += mod;
        }
      }
    }
  }
  long long inas = 0;
  for (int i = A; i <= B; i++) inas += dp[i][7];
  cout << inas % mod << endl;
  return 0;
}