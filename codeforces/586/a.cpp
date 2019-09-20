#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int z = 0, o = 0;
  for (int i = 0; i < n; ++i) {
    z += s[i] == 'z';
    o += s[i] == 'n';
  }
  for (int i = 0; i < o; ++i)
    printf("1 ");
  for (int i = 0; i < z; ++i)
    printf("0 ");
  printf("\n");
  return 0;
}
