#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k;
int c[N];
bool cap[N];

int main() {
  scanf("%d%d", &n, &k);
  long long sum = 0;
  for(int i = 0; i<n; i++)
    scanf("%d", c+i), sum += c[i];
  long long sum_cap = 0;
  for(int i = 0; i<k; i++) {
    int x;
    scanf("%d", &x);
    x--;
    cap[x] = true;
    sum_cap += c[x];
  }
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    if(cap[i]) {
      ans += 1LL * (sum-c[i]) * c[i];
    }
    else {
      long long now = sum_cap;
      if(!cap[(i+n-1) % n])
        now += c[(i+n-1) % n];
      if(!cap[(i+1) % n])
        now += c[(i+1) % n];
      ans += now * c[i];
    }
  }
  ans /= 2;
  cout << ans << endl;
  return 0;
}