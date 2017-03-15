#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e17;
const int N = 2e7 + 7;
long long d[N];

int main() {
  int n;
  long long x, y;
  cin >> n >> x >> y;
  for (int i = 0; i <= n; i++)
    d[i] = i * x;
  for (int i = 0; i <= n; i++) {
    d[i+i] = min(d[i+i], d[i] + y);
    d[i+i+1] = min(d[i+i+1], d[i] + x + y);
    d[i+i-1] = min(d[i+i-1], d[i] + x + y);
  }
  cout << d[n] << endl;
  return 0;
} 