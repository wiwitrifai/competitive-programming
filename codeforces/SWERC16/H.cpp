#include <bits/stdc++.h>

using namespace std;

int D, H;
long long C[33][33];
set < long long > st;

void DFS(int last, int n, int sum, long long now)
{
  if (n == D) {
    if (sum == H)
      st.insert(now);
    return;
  }
  for (int i = min(last, H-sum); i > 0; i--) {
    DFS(i, n+1, sum+i, now * C[sum+i][i]);
  }
  if (sum == H)
    DFS(0, n+1, sum, now);
}

int main()
{
  for (int i = 0; i < 33; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  scanf("%d%d", &D, &H);
  H--;
  DFS(H, 0, 0, 1);
  for (long long v : st)
    printf("%lld\n", v);
  return 0;
}