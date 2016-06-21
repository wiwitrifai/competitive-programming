#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n, a[N];
long long m;

int main() {
  scanf("%d%lld", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  int r = n-1;
  deque< int > dq;
  long long sum = 0, act = 0;
  long long ans = 0;
  for(int i = n-1; i>=0; i--) {
    while(!dq.empty() && a[dq.front()] <= a[i]) {
      int fr = dq.front();
      dq.pop_front();
      int ro = dq.empty() ? r+1 : dq.front();
      sum += 1LL*(a[i]-a[fr]) * (ro - fr);
    }
    sum += a[i];
    act += a[i];
    dq.push_front(i);
    while(!dq.empty() && sum - act > m) {
      sum -= a[dq.back()];
      act -= a[r];
      if(dq.back() == r)
        dq.pop_back();
      r--;
    }
    // cout << i << " " << r << endl;
    ans += r - i + 1;
  }
  printf("%lld\n", ans);
  return 0;
}