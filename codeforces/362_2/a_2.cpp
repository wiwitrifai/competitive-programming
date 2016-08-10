#include <bits/stdc++.h>

using namespace std;

int main() {
  long long t, s, x;
  cin >> t >> s >> x;
  long long a = ((x-t)/s) * s + t, b = ((x-t-1)/s) * s + t + 1;
  while(a >= x) a -= s;
  while(b >= x) b -= s;
  while(a < x) a += s;
  while(b < x) b += s;
  while(a < t) a += s;
  while(b <= t) b += s;
  if((x == a) || (x == b && b > t+1))
    puts("YES");
  else
    puts("NO");

  return 0;
}