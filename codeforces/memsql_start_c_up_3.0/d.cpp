#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, LN = 20;

int n, p[N], id[N];

int sp[LN][N];

int get(int l, int r) {
  int len = r-l + 1;
  int z = 31 - __builtin_clz(len);
  return min(sp[z][l], sp[z][r-(1<<z) + 1]);
}

int sel[N];

int main() {
  scanf("%d", &n);
  multiset<int> neg, pos, net; 
  for (int i = 0; i < n; i++) {
    scanf("%d", p+i);
  }
  for (int i = 0; i < n; i++) {
    sp[0][i] = p[i];
    id[i] = i;
  }
  for (int j = 0; j + 1 < LN; j++) {
    for (int i = 0; i + (1 << (j+1)) <= n; i++) {
      sp[j+1][i] = min(sp[j][i], sp[j][i+(1 << j)]);
    }
  }
  sort(id, id+n, [](int le, int ri) {
    if (p[le] != p[ri])
      return p[le] > p[ri];
    return le > ri;
  });
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = id[i];
    int ri = cur-1;
    while (ri >= 0) {
      int l = 0, r = ri;
      while (l < r) {
        int m = (l + r + 1) / 2;
        if (get(m, ri) >= p[cur])
          r = m-1;
        else
          l = m;
      }
      ri = l;
      if (p[r] < p[cur] && !sel[r])
        break;
      ri = l-1;
    }
    if (ri >= 0) {
      sel[ri] = cur+1;
      ans += p[cur] - p[ri];
      cerr << ri << " "<< cur << endl;
    }
  }
  printf("%lld\n", ans);
  return 0;
}