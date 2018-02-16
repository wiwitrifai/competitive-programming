#include <bits/stdc++.h>

using namespace std;

const string NAME = "easy";

const int N = 15;

int a[N][N], p[N];

int main() {
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
  
  memset(a, -1, sizeof(a));
  int n, k;
  scanf("%d %d", &n, &k);
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    maxi = max(maxi, p[i]);
    for (int j = 0; j < p[i]; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int sum = 0, udah = 0;
  for (int j = 0; j < maxi; j++) {
    for (int i = 0; i < n; i++) {
      if (udah == k) break;
      if (a[i][j] == -1) {
        sum += 50;
        udah++;
      } else {
        if (a[i][j] >= sum) {
          sum += a[i][j];
          udah++;
        }
      }
    }
  }
  if (udah < k) {
    sum += (k - udah) * 50;
  }
  cout << sum << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}