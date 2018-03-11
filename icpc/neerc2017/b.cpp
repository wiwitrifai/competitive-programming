// by luqman
#include <bits/stdc++.h>

using namespace std;

int v[5];
int w, h;
bool ok;

void print(int n, int m) {
  if (n <= w && m <= h) {
    ok = 1;
  }
}

void cek(int n, int m) {
  print(n, m);
  print(m, n);
}

int main() {
  for (int i = 0; i < 3; i++) scanf("%d", v + i);
  scanf("%d %d", &w, &h);
  sort(v, v + 3);
  do {
    int a = v[0];
    int b = v[1];
    int c = v[2];
    cek(2*a+c, 2*a+2*b);
    cek(2*c+b, 2*a+2*c);
    cek(2*a+2*c, a+b+c);
    cek(b+2*c, 2*a+2*c);
    cek(a+b+c, 2*a+2*c);
    cek(b+2*c, 2*a+b+c);
    cek(a+b+c, 2*c+a+b);
    cek(a+c, 3*b+a+c);
    cek(a+b+c, 2*a+b+c);
    cek(2*a+b, 2*c+a+b);
  } while (next_permutation(v, v + 3));
  puts(ok? "Yes" : "No");
  return 0;
}