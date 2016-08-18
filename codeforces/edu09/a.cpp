#include <bits/stdc++.h>

using namespace std;

int n, p;
int add[50];

int main() {
  scanf("%d%d", &n, &p);
  p/=2;
  for(int i = 0; i<n; i++) {
    string s;
    cin >> s;
    if(s.size() < 5)
      add[i] = 0;
    else
      add[i] = 1;
  }
  long long now = 0;
  long long sum = 0;
  for(int i = n-1; i>=0; i--) {
    now = now*2 + add[i];
    sum += now;
  }
  sum *= p;
  cout << sum << endl;

  return 0;
}