#include <bits/stdc++.h>

using namespace std;

const int N = 1003;
int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i<=n; i++) {
    scanf("%d", a+i);
    a[i] |= a[i-1];
  }
  for(int i = 1; i<=n; i++) {
    scanf("%d", b+i);
    b[i] |= b[i-1]; 
  }
  cout << (long long)a[n] + (long long)b[n] << endl;
  return 0;
}