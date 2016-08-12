#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
int c[N];
string s[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", c+i);
  }
  for(int i = 0; i<n; i++) {
    cin >> s[i];
  }
  string a, b;
  long long ca, cb;
  a = b = s[0];
  reverse(b.begin(), b.end());
  ca = 0; cb = c[0];
  for(int i = 1; i < n; i++) {
    string aa = s[i];
    string bb = s[i];
    reverse(bb.begin(), bb.end());
    long long caa = inf, cbb = inf;
    if(aa >= a)
      caa = min(caa, ca);
    if(aa >= b)
      caa = min(caa, cb);
    if(bb >= a)
      cbb = min(cbb, ca+c[i]);
    if(bb >= b)
      cbb = min(cbb, cb+c[i]);
    ca = caa;
    cb = cbb;
    a = aa;
    b = bb;
  }
  long long ans = min(ca, cb);
  if(ans >= inf)
    ans = -1;
  cout << ans << endl;

  return 0;
}