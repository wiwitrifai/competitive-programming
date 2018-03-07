#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m[N], r[N], p, q;

int main() {
  scanf("%d", &n);
  p = 0;
  for(int i = 0; i<n; i++) {
    scanf("%d%d", m+i, r+i);
    p += (m[i]>r[i]);
  }
  q = n-p;
  int i = 1;
  vector< pair< int , int> > ans;
  while(p <= q && i < n) {
    if(m[i] > r[i] && m[i-1] > r[i-1]) {
      i++;
      continue;
    }
    if(m[i] <= r[i] && m[i-1] <= r[i-1]) {
      q--;
      ans.push_back(make_pair(i, i+1));
      i++;
    }
    else if((m[i]+m[i-1]) > (r[i]+r[i-1])) {
      q--;
      ans.push_back(make_pair(i, i+1));
      i++;
    }
    i++;
  }
  if(p <= q)
    puts("-1");
  else {
    printf("%d\n", ans.size());
    for(int i = 0; i<ans.size(); i++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}