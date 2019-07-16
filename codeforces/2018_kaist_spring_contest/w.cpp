#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int sa[N], pos[N], tmp[N], gap, n;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  for(int i = 0; i<n; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + n, cmp_sa);
    for(int i = 1; i<n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<n; i++) pos[sa[i]] = tmp[i];
    if(tmp[n-1] == n-1) break;
  }
}


int main() {
  scanf("%d %s", &n, s);
  int off = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      off = i;
      break;
    }
  }
  if (off == -1) {
    puts("0 0");
    return 0;
  }
  build_sa();
  int best = off;
  for (int i = off+1; i < n; ++i) {
    if (s[i] == '0') continue;
    if (best == -1 || pos[i] > pos[best])
      best = i;
  }
  printf("%d %d\n", off, best - off);
  return 0;
}
