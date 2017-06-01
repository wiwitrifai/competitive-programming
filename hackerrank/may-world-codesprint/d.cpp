#include <bits/stdc++.h>

using namespace std;

const int N = 1<<12, M = 3005;
long long x[N][M], cnt[M];

int main() {
  int a[5];
  for(int i = 0; i<4; i++)
    scanf("%d", a+i);
  sort(a, a+4);
  for(int i = 1; i<=a[0]; i++)
    for(int j = i; j<=a[1]; j++) {
      x[i^j][j]++;
      cnt[j]++;
    }
  for(int i = 0; i<N; i++)
    for(int j = 1; j<a[1]; j++)
      x[i][j+1] += x[i][j];
  long long sum = 0, sub = 0;
  for(int i = 1; i<=a[2]; i++)
    for(int j = i; j<=a[3]; j++) {
      sum += cnt[i];
      sub += x[i^j][i];
    }
  cout << sum - sub << endl;
  return 0;
}