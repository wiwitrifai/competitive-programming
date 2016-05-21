#include <bits/stdc++.h>

using namespace std;

long long j, s, m;
int main() {
  cin >> j >> s >> m;
  m -= j;
  m/=s;
  if(m & 1)
    puts("Unlucky Chef");
  else
    puts("Lucky Chef");

  return 0;
}