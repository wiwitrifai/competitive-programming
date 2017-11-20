  #include <bits/stdc++.h>

  using namespace std;

  const int N = 1024;

  int a[N];
  int n;

  int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d",a+i);
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
      ans += (a[i-1] - a[i]) * (a[i+1] - a[i]) > 0;
    }
    printf("%d\n", ans);
    return 0;
  }