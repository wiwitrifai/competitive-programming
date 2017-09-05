#include <bits/stdc++.h>

using namespace std;

const int N = 4e6;

int a[N], ans[N], d[N];
int val[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n * 2; i++)
    scanf("%d", a+i);
  sort(a, a+2*n);
  int k = 0;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i+1; j < 2 * n; j++)
      d[k++] = a[j] - a[i];
  }
  sort(d, d+k);
  vector<int> candid;
  int last = d[0], cnt = 0;
  for (int i = 0; i < k; i++) {
    if (last != d[i]) {
      if (cnt >= n && last > 0)
        candid.push_back(last);
      cnt = 0;
      last = d[i];
    }
    cnt++;
  }
  if (cnt >= n && last > 0)
    candid.push_back(last);
  int x = -1, m = 0;
  for (int c : candid) {
    x = c;
    m = 0;
    for (int i = 0, j = 0; i < 2 * n; i++) {
      if (val[i] == x) continue;
      val[i] = x;
      j = max(j, i+1);
      while (j < 2 * n && (val[j] == x || a[j] < a[i] + x)) j++;
      if (j >= 2 * n || a[j] != a[i] + x) {
        break;
      }
      val[j] = x;
      ans[m++] = a[j];
      j++;
    }
    if (m == n)
      break;
    x = -1;
  }
  printf("%d\n", x);
  if (m == n) {
    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}