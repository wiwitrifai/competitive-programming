#include <bits/stdc++.h>

using namespace std;

int x[50], m;
bool ispal(int n, int b) {
  m = 0;
  while(n) {
    x[m++] = n % b;
    n /= b;
  }
  bool ret = true;
  for(int i = 0; i<m-i-1; i++)
    ret &= (x[i] == x[m-i-1]);
  return ret;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  long long sum = 0;
  for(int i = 1; i<=n; i++) {
    if(ispal(i, 10) && ispal(i, k))
      sum += i;
  }
  cout << sum << endl;
  return 0;
}