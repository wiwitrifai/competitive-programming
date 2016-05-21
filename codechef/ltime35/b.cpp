#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k;
long long a[N];
set< pair<long long, pair<int, int> > > st;

int main() {
  scanf("%d%d", &n, &k);
  long long sum = 0;
  for(int i = 0; i<n; i++) {
    scanf("%lld", a+i);
    sum += a[i];
  }
  st.insert(make_pair(sum, make_pair(0, n-1)));
  while(!st.empty()) {
    pair<long long, pair<int, int>> now = *st.rbegin();
    st.erase(now);
    k--;
    printf("%lld%c", now.first, k ? ' ' : '\n');
    if(k == 0)
      break;
    if(now.second.first < now.second.second) {
      st.insert(make_pair(now.first - a[now.second.first],make_pair(now.second.first+1, now.second.second)));
      st.insert(make_pair(now.first - a[now.second.second],make_pair(now.second.first, now.second.second-1)));
    }
  }
  return 0;
}