#include <bits/stdc++.h>

using namespace std;

long long kali[5];
int p[5];
const int N = 1024;
long long C[N][N];

int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  for (int i = 1; i < 5; i++) {
    for (int j = 0; j < i; j++)
      p[j] = j;
    kali[i] = 0;
    do {
      bool ok = 1;
      for (int j = 0; j < i; j++)
        ok &= p[j] != j;
      kali[i] += ok;
    } while (next_permutation(p, p+i));
  }
  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = 1;
  for (int i = 2; i <= k; i++) {
    ans += C[n][i] * kali[i];
  }
  cout << ans << endl;
  return 0;
}