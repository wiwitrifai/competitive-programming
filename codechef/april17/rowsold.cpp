#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0, sum = 0;
    long long ans = 0;
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == '0')
        sum++;
      else {
        if (s[i+1] == '0') cnt++;
        ans += cnt + sum;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
