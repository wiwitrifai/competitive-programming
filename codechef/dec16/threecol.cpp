#include <bits/stdc++.h>

using namespace std;

int x[1000];
int to[3][3];

int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (i == j)
        to[i][j] = i;
      else
        to[i][j] = 0 + 1 + 2 - i - j;
  int n;
  scanf("%d", &n);
  long long tot = 1;
  for (int i = 1; i < n; i++)
    tot *= 3;
  for (int num = 0; num < tot; num++) {
    // cerr << num << endl;
    int now = num;
    x[0] = 0;
    cout << x[0];
    for (int i = 1; i < n; i++) {
      x[i] = now % 3;
      now /= 3;
      cout << " " << x[i]; 
    } 
    cout << endl;
    bool ok = true;
    while (ok) {
      ok = false;
      for (int i = 0; i + 1 < n; i+= 2) {
        int c = to[x[i]][x[i+1]];
        x[i] = x[i+1] = c;
      }
      for (int i = 1; i + 1 < n; i+= 2) {
        int c = to[x[i]][x[i+1]];
        x[i] = x[i+1] = c;
      }
      for (int i = 0; i + 1 < n; i+= 2) {
        int c = to[x[i]][x[i+1]];
        x[i] = x[i+1] = c;
      }
      for (int i = 0; i + 1 < n; i++) {
        int c = to[x[i]][x[i+1]];
        x[i] = x[i+1] = c;
      }
      int c = x[0];
      for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
        if (x[i] != c) {
          ok = true;
        }
      }
      cout << endl;
    }
    cerr << "done" << endl;
  } 
  return 0;
}