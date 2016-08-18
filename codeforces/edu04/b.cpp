#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    a[x] = i;
  }
  long long ans = 0;
  for(int i = 1; i<n; i++)
    ans += abs(a[i]-a[i+1]);
  cout << ans << endl;
  return 0;
}