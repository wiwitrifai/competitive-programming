#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    p[i] = i;
  do {

  } while (next_permuatation(p, p+n));

  return 0;
}