#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int p[N];

bool cek[N];

int main() {
  int n;
  scanf("%d", &n);
  --n;
  for (int i = 0; i < n; ++i) p[i] = i;
  long long tot = 0;
  do {
    for (int i = 0; i <= n; ++i) cek[i]= 0;
    int cnt = 0, cost = 0;
    for (int i = 0; i < n; ++i) {
      int x = p[i];
      if (cek[x] == 0) ++cnt, cek[x] = 1;
      if (x + 1 <= n && cek[x+1] == 0) ++cnt, cek[x+1] = 1;
      if (cnt > n) {
        cost = i+1;
        break;
      }
    }
    // cerr << cost << endl;
    tot += cost;
  } while (next_permutation(p, p+n));
  cout << tot << endl;
  return 0;
}