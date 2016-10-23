/**
  IEEExtreme Programming Contest 10
  Problem : Game of Stones 1
  Solver  : Luqman Arifin S
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int nim = 0;
    int g;
    scanf("%d", &g);
    while (g--) {
      int n;
      scanf("%d", &n);
      for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        nim ^= (a[i] / 2) % 2;
      }
    }
    puts(nim? "Alice" : "Bob");
  }
  return 0;
}