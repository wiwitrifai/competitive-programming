#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int n, m, r[N], qr[N], c[N], qc[N];
int main() {
  int k;
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i<=k; i++) {
    int q, no, a;
    scanf("%d%d%d", &q, &no, &a);
    no--;
    if(q == 1) {
      r[no] = a;
      qr[no] = i;
    }
    else {
      c[no] = a;
      qc[no] = i;
    }
  }
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++) {
      printf("%d ", (qr[i] > qc[j]) ? r[i] : c[j]);
    }
    printf("\n");
  }

  return 0;
}