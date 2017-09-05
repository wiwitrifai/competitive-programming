#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int a[N][N], b[N][N], n;

bool cek() {
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
      if (a[i][j] != b[i][j])
        return false;
  return true;
}

void fliph() {
  for (int i = 0; i < n; i++) {
    for (int j = 0, k = n-1; j < k; j++, k--) {
      swap(b[i][j], b[i][k]);
    } 
  }
}

void flipv() {
  for (int i = 0; i < n; i++) {
    for (int j = 0, k = n-1; j < k; j++, k--) {
      swap(b[j][i], b[k][i]);
    } 
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i< n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", a[i]+j);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", b[i]+j);
  }
  fliph();
  if (cek()) {
    puts("1");
    return 0;
  }
  fliph();
  flipv();
  if (cek()) {
    puts("1");
    return 0;
  }
  puts("0");

  return 0;
}