#include <bits/stdc++.h>

using namespace std;

long long pw[40];
map<long long, int> mp[40];

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  pw[0] = 1;
  for(int i = 1; i<32; i++) {
    pw[i] = pw[i-1]<<1;
  }
  for(int i = 0; i<n; i++) {
    int a;
    scanf("%d", &a);
    for(int j = 1; j<32; j++) {
      if(pw[j] > a) {
        if(mp[j].count(a))
          ans += mp[j][a];
        mp[j][pw[j]-a]++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}