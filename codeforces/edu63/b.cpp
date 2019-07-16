#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ada = 0;
  for (int i = 0; i + 11 <= n; ++i) {
    ada += s[i] == '8';
  }
  int move = n - 11;
  int need = move + 1 - ada;
  int can = (move + 1) / 2;
  puts(can >= need ? "YES" : "NO");
  return 0;
}
