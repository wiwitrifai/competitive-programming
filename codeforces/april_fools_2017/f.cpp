#include <bits/stdc++.h>

using namespace std;
int a[55];

int main() {
  time_t startt = clock();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  while ((double)(clock()-startt) * 1000/CLOCKS_PER_SEC < 1700);
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}