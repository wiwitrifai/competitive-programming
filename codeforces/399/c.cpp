#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N], b[N], init[N];

int main() {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  memset(init, 0, sizeof init);
  for (int i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);
    init[s]++;
  }
  int mod = -1;
  memcpy(a, init, sizeof a);
  for (int z = 0; z < k; z++) {
    memcpy(b, a, sizeof b);
    int cur = 0;
    for (int i = 0; i < N; i++) if (a[i]) {
      int now = a[i];
      if (cur & 1)
        now--;
      int move = (now+1)/2;
      b[i] -= move;
      b[i^x] += move;
      cur += a[i];
    }
    memcpy(a, b, sizeof a);
    bool same = 1;
    for (int i = 0; i < N; i++)
      if (a[i] != init[i]) {
        same = 0;
        break;
      }
    if (same) {
      mod = z+1;
      break;
    }
  }
  if (mod != -1) {
    k %= mod;
    memcpy(a, init, sizeof a);
    for (int z = 0; z < k; z++) {
      memcpy(b, a, sizeof b);
      int cur = 0;
      for (int i = 0; i < N; i++) if (a[i]) {
        int now = a[i];
        if (cur & 1)
          now--;
        int move = (now+1)/2;
        b[i] -= move;
        b[i^x] += move;
        cur += a[i];
      }
      memcpy(a, b, sizeof a);
    }
  }
  int mi = 0, ma = N-1;
  while (a[mi] == 0) mi++;
  while (a[ma] == 0) ma--;
  cout << ma << " " << mi << endl;
  return 0;
}