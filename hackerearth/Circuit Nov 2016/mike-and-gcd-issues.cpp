#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector< int > fac[N];
int id[N], ans[N], a[N];

int main() {
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i)
      fac[j].push_back(i);
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
  }
  memset(ans, -1, sizeof ans);
  memset(id, -1, sizeof id);
  for (int i = 1; i <= n; i++) {
    for (int j : fac[a[i]]) {
      if (ans[i] < id[j])
        ans[i] = id[j];
      id[j] = i;
    }
  }
  memset(id, -1, sizeof id);
  for (int i = n; i > 0; i--) {
    for (int j : fac[a[i]]) {
      if (id[j] != -1) {
        if (ans[i] == -1)
          ans[i] = id[j];
        else if (abs(id[j]-i) < abs(ans[i]-i))
          ans[i] = id[j];
      }
      id[j] = i;
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}