#include <bits/stdc++.h>

using namespace std;

const int N = 303;
char s[N][N];
bool can[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", s[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      can[i][j] = 1;
      for (int k = 0; k < n; ++k)
        can[i][j] &= s[(i+k) % n][j] == s[i][(j+k) % n]; 
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    bool bisa = 1;
    for (int j = 0; j < n; ++j) {
      bisa &= can[(i+j) % n][j];
    }
    cnt += bisa;
  }
  cout << 1LL * cnt * n << endl;
  return 0;
}