#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, id[N], a[N];
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    id[i] = i;
  }
  sort(id, id+n, [](int x, int y) { return (a[x] == a[y] ? x < y : a[x] < a[y]); });
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    int j = i;
    while(j < n && a[id[j]] == a[id[i]]) {
      if(2*(j-i+1) <= id[j]-id[i]+1) {
        j += id[j] - id[i] - 2*(j-i);
      }
      else {
        int diff = 2*(j-i+1) - id[j]+id[i] -1;
        for(int k = max(id[i]-diff, 0); k<=id[i]; k++)
          ans += min(diff-id[i]+k, n-id[j]);
        j++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}