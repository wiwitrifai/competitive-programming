#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, a, c;
  int p, q;
  scanf("%d %d %d %d %d", &h, &a, &c, &p, &q);
  int butuh = (p + a - 1) / a;
  int jamu = 0;
  while (h - (butuh-1) * q <= 0) {
    jamu++;
    h += c - q;
  }
  printf("%d\n", jamu + butuh);
  for (int i = 0; i < jamu; ++i)
    printf("HEAL\n");
  for (int i = 0; i < butuh; ++i)
    printf("STRIKE\n");
  return 0;
}