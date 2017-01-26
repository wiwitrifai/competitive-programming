#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int le[N], ri[N];
char a[N], b[N];

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a), m = strlen(b);
  int id = 0;
  for (int i = 0; i < m; i++) {
    while (id < n && a[id] != b[i]) id++;
    le[i] = id;
    if (id < n) id++;
  }
  id = n-1;
  for (int i = m-1; i >= 0; i--) {
    while (id >= 0 && a[id] != b[i]) id--;
    ri[i] = id;
    if (id >= 0) id--;
  }
  int ansl, ansr = 0;
  ansl = 0;
  ansr = 0;
  while (ansr < m && ri[ansr] < 0) ansr++;
  int nowr = ansr;
  for (int i = 0; i < m; i++) {
    if (le[i] >= n)
      break;
    if (nowr < i+1)
      nowr = i+1;
    while (nowr < m && ri[nowr] <= le[i]) nowr++;
    if (nowr-i-1 < ansr-ansl)
      ansl = i+1, ansr = nowr;
  }
  if (ansr - ansl == m)
    puts("-");
  else if (ansr-ansl == 0)
    printf("%s\n", b);
  else {
    b[ansl] = '\0';
    printf("%s%s\n", b, b+ansr);
  }

  return 0;
}