#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int a[N], b[N];
int n;

int cek() {
  int separo = n/2;
  int ans = 0;
  if (b[0] != separo) {
    for (int i = 0; i < n; i++) if (b[i] == separo) {
      swap(b[i], b[0]);
      ans++;
      break;
    }
  }
  if (b[n-1] != separo+1) {
    for (int i = 0; i < n; i++) if (b[i] == separo+1) {
      swap(b[i], b[n-1]);
      ans++;
      break;
    }
  }
  int cnt = 0;
  for (int i = 1; i + 1 < n; i++) {
    if ((i & 1))
      cnt += b[i] <= separo;
    else
      cnt += b[i] > separo;
  }
  return ans + cnt/2;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    for (int i = 0; i < n; i++)
      b[i] = a[i];
    int ans = cek();
    for (int i = 0; i < n; i++)
      b[i] = n+1-a[i];
    ans = min(ans, cek());
    for (int i = 0; i < n; i++)
      b[i] = a[n-1-i];
    ans = min(ans, cek());
    for (int i = 0; i < n; i++)
      b[i] = n+1-a[n-1-i];
    ans = min(ans, cek());
    
    printf("%d\n", ans);
  }
  return 0;
}