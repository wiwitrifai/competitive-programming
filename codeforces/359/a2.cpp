#include <bits/stdc++.h>

using namespace std;

int n, dis;
long long x;
int main() {
  cin >> n >> x;
  dis = 0;
  for(int i = 0; i<n; i++) {
    char s;
    int v;
    scanf(" %c%d", &s, &v);
    if(s == '+')
      x += v;
    else
      if(v <= x)
        x -= v;
      else
        dis++;
  }
  cout << x << " " << dis << endl;
  return 0;
}