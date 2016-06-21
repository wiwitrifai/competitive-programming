#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int n;
long long a[N], b[N];
int ia[N], ib[N];
int main() {
  freopen("black.in", "r", stdin);
  freopen("black.out", "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    cin >> a[i];
    ia[i] = ib[i] = i;
  }
  for(int i = 0; i<n; i++)
    cin >> b[i];
  sort(ia, ia+n, [](int x, int y) {
    return a[x] < a[y];
  });
  sort(ib, ib+n, [](int x, int y) {
    return b[x] < b[y];
  });
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    long long tmp = a[ia[i]]-b[ib[i]];
    if(tmp < 0)
      tmp = -tmp;
    ans += tmp;
  }
  cout << ans << endl;
  for(int i = 0; i<n; i++)
    printf("%d %d\n", ia[i]+1, ib[i]+1);

  return 0;
}