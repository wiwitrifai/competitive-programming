#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int cnt[202];
int med;
int a[N];


int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < d; i++)
    cnt[a[i]]++;
  int ans = 0;
  for (int i = d; i < n; i++) {
    int idl = 0, idr = 0;
    int sum = 0;
    for (int j = 0; j <= 200; j++) {
      sum += cnt[j];
      if (sum * 2 > d) {
        idr = j;
        sum -= cnt[j];
        if (sum * 2 < d)
          idl = j;
        break;
      }
      else if (cnt[j]) {
        idl = j;
      }
    }
    int mid = idr+idr;
    if ((d & 1) == 0)
      mid = idr + idl;
    if (a[i] >= mid)
      ans++; 
    cnt[a[i]]++; 
    cnt[a[i-d]]--;
  }
  printf("%d\n", ans);
  return 0;
}