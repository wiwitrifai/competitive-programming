#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LN = 20, A = 830;

struct sparse {
  int n;
  int a[LN][N];
  int * x;
  sparse(int n, int * x) : n(n), x(x) {
    for (int i = 0; i < n; i++)
      a[0][i] = i;
    for (int i = 0; i + 1 < LN; i++) {
      int ma = n - (1<< (i+1));
      for (int j = 0; j <= ma; j++) 
        a[i+1][j] = (x[a[i][j]] < x[a[i][j + (1<<i)]]) ? a[i][j] : a[i][j+(1<<i)]; 
    }
  }
  int get(int l, int r) {
    int len = r-l;
    int lg = 31 - __builtin_clz(len);
    return x[a[lg][l]] < x[a[lg][r-(1<<lg)]] ? a[lg][l] : a[lg][r-(1<<lg)];
  }
};

int a[N], pre[N];
sparse * sp;
const int B = 42;
struct bit {
  int a[B];
  bit() {
    memset(a, -1, sizeof a);
  }
  void upd(int x, int v) {
    for (; x < B; x += x&(-x))
      a[x] = max(a[x], v);
  }
  int get(int x = B-1) {
    int ret = -1;
    for (; x > 0; x -= x&(-x))
      ret = max(ret, a[x]);
    return ret;
  }
};
bit fen[A];
int occ[100];
const int off = 41; 

int main() {
  memset(occ, -1, sizeof occ);
  int n;
  scanf("%d", &n);
  int now = 0;
  bool neg = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    neg &= a[i] <= 0;
    pre[i] = now;
    now += a[i];
  }
  if (neg) {
    printf("%d %d\n", 0, n);
    return 0;
  }
  pre[n] = now;
  sp = new sparse(n, pre);
  int g = -1e9, m = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      for (int j = A-1-a[i]; j > 0; j--) {
        int id = fen[j].get(a[i]-1);
        if (id < 0) continue;
        fen[j+a[i]].upd(a[i], id);
      }
      fen[a[i]].upd(a[i], i);
    }
    occ[a[i] + off] = i;
    int last = 0;
    for (int j = A-1; j > 0; j--) {
      int id = fen[j].get();
      if (last <= id) {
        int ig = sp->get(last, id+1);
        int ng = pre[i+1] - pre[ig] - j;
        if (ng > g) {
          g = ng;
          m = i-ig + 1;
          cnt = 1;
        }
        else if (ng == g) {
          if (i-ig+1 == m)
            cnt++;
          else if (m > i-ig+1)
            cnt = 1, m = i-ig+1;
        }
        last = id + 1;
      }
    }
    for (int j = 0; j >= -41; j--) {
      int id = occ[j+off];
      if (last <= id) {
        int ig = sp->get(last, id+1);
        int ng = pre[i+1] - pre[ig] - j;
        if (ng > g) {
          g = ng;
          m = i-ig + 1;
          cnt = 1;
        }
        else if (ng == g) {
          if (i-ig+1 == m)
            cnt++;
          else if (m > i-ig+1)
            cnt = 1, m = i-ig+1;
        }
        last = id + 1;
      } 
    }
    assert(last == i+1);
  }
  if (g == 0)
    assert(cnt == n);
  printf("%d %d\n", g, cnt);
  return 0;
}