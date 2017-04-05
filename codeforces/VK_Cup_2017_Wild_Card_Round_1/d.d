module main;

import std.c.stdio;
import std.algorithm.sorting;

int main(string[] argv)
{
  int n, l, r;
  scanf("%d %d %d", &n, &l, &r);
  int [] a = new int[n];
  int [] b = new int[n];
  int [] aa = new int[r-l+1];
  int [] bb = new int[r-l+1];
  for(int i = 0; i<n; i++)
    scanf("%d", &a[i]);
  for(int i = 0; i<n; i++)
    scanf("%d", &b[i]);
  bool ok = 1;
  for (int i = 0; i < l-1; i++)
    if (a[i] != b[i])
      ok = 0;
  for (int i = r; i < n; i++)
    if (a[i] != b[i])
      ok = 0;
  for (int i = l; i <= r; i++) {
    aa[i-l] = a[i-1];
    bb[i-l] = b[i-1];
  }
  aa.sort();
  bb.sort();
  for (int i = 0; i < r-l+1; i++)
    if (aa[i] != bb[i])
      ok = 0;
  if (ok)
    printf("TRUTH");
  else
    printf("LIE");
  return 0;
}