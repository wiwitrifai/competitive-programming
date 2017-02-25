#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6, inf = 1e9 + 7;

int cnt[N];
int ma[N];
int next(int x, int c = -1) {
  x++;
  while (x < N && (cnt[x] == 0 || x == c)) x++;
  return x; 
}
void finish(int sisa, int c, int st = -1) {
  int id = next(0, c);
  if (st != -1 && st != c)
    id = st;
  if ((sisa & 1) || (id != st && c < id) || (st == c)) {
    while (sisa) {
      if (sisa && cnt[c]) {
        printf("%d ", c);
        cnt[c]--;
        sisa--;
      }
      if (sisa) {
        if (cnt[id] == 0)
          id = next(id, c);
        printf("%d ", id);
        cnt[id]--;
        sisa--;
      }
    }
  }
  else {
    bool ok = 1;
    while (sisa) {
      if (sisa) {
        if (cnt[id] == 0)
          id = next(id, c);
        printf("%d ", id);
        cnt[id]--;
        sisa--;
        if (ok) {
          id = next(0, c);
          ok = 0;
        }
      }
      if (sisa && cnt[c]) {
        printf("%d ", c);
        cnt[c]--;
        sisa--;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  ma[N-1] = N-1;
  for (int i = N-2; i >= 0; i--)
    ma[i] = cnt[i] >= cnt[ma[i+1]] ? i : ma[i+1];
  int v = ma[0];
  if (n & 1) {
    if (cnt[v] + cnt[v] > n + 1) {
      puts("-1");
      return 0;
    }
    if (cnt[v] + cnt[v] >= n) {
      finish(n, v, v);
      printf("\n");
      return 0;
    }
  }
  else {
    if (cnt[v] + cnt[v] > n) {
      puts("-1");
      return 0;
    }
    if (cnt[v] + cnt[v] >= n) {
      finish(n, v);
      printf("\n");
      return 0;
    }
  }
  int a, b;
  a = next(0), b = next(a);
  for (int sisa = n; sisa > 0; sisa--) {
    if (cnt[a] == 0)
      a = next(a, b);
    if (cnt[b] == 0)
      b = next(b, a);
    int c = ma[max(a, b) + 1];
    if (cnt[b] >= cnt[c])
      c = b; 
    if (cnt[a] >= cnt[c])
      c = a;
    if (cnt[c] + cnt[c] >= sisa) {
      finish(sisa, c, cnt[c] > sisa - cnt[c] ? c : a);
      printf("\n");
      return 0;
    }
    printf("%d ", a);
    cnt[a]--;
    swap(a, b);
  }
  printf("\n");
  return 0 ;
}