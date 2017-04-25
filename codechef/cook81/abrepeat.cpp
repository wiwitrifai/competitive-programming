#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    long long b = 0;
    for (int i = 0; i < n; i++)
      b += s[i] == 'b';
    long long sum = 1LL * k * (0 + 1LL * (k-1) * b)/2;
    long long ans = 0;
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == 'b')
        sum += k;
      else if (s[i] == 'a')
        ans += sum;
    }
    cout << ans << endl;
  }
  return 0;
}