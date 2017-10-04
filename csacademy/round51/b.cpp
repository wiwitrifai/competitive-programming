#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N], id[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    id[i] = i;
  }
  sort(id, id+n, [](int l, int r) {
    int le = l + a[l], ri = r + a[r];
    if (le == ri)
      return a[l] < a[r];
    return le < ri;
  });
  for (int i = 0; i < n; i++)
    printf("%d ", id[i]+1);
  return 0;
}