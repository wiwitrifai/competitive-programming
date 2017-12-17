#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N];

int main() {
  scanf("%s", a);
  int n = strlen(a);
  int ans = 0;
  for (int i = 0, j = n-1; i < j;) {
    if (a[i] != a[j]) {
      if (a[i] == 'x') i++, ans++;
      else if (a[j] == 'x') j--, ans++;
      else {
        puts("-1");
        return 0;
      }
    }
    else
      i++, j--;
  }
  cout << ans << endl;
  return 0;
}