#include <bits/stdc++.h>

using namespace std;
// suffix array
const int N = 1e5 + 5;
char s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, n;

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

void build_lcp() {
  for(int i = 0, k = 0; i<n; i++) if(pos[i] - n + 1) {
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k]; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  build_sa();
  build_lcp();
  int off = sa[0], len = n-sa[0], occ = 1, coff = off, clen = len, best = 1;
  for (int i = 0; i+1 < n; i++) {
    if (lcp[i] > 0) {
      clen = min(clen, lcp[i]);
      occ++;
    }
    else {
      occ = 1;
      coff = sa[i+1];
      clen = n-coff;
    }
    if (best < occ || (best == occ && clen > len)) {
      best = occ;
      len = clen;
      off = coff;
    }
  }
  s[off+len] = 0;
  printf("%s\n", s+off);
  return 0;
}