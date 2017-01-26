#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  vector< long long > d;
  for (long long i = 1; i * i <= n; i++) if ((n % i) == 0) {
    d.push_back(i);
    long long j = n/i;
    if (i != j)
      d.push_back(j);
  }
  sort(d.begin(), d.end());
  if (k > d.size())
    puts("-1");
  else
    cout << d[k-1] << endl;
  return 0;
}