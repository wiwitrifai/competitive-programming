#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n; 
  long long k = 1; 
  while(k*(k+1)/2 < n)
    k++;
  k--;
  n -= k *(k+1)/2;
  cout << n << endl;;
  return 0;
}