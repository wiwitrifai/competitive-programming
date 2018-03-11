// by wiwit
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
pair<int, int> pp[N];

bool cmp(pair<int, int> a, pair< int, int> b) {
  if(a.first <= a.second && b.first <= b.second)
    return a.first == b.first ? a.second > b.second : a.first < b.first;
  if(a.first > a.second && b.first > b.second)
    return a.second == b.second ? a.first > b.first : a.second > b.second;
  return a.first <= a.second;
}
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    pp[i] = make_pair(a, b);
  }
  sort(pp, pp + n, cmp);
  long long cur = 0;
  long long ext = 0;
  for(int i = 0; i<n; i++) {  
    long long add = max(pp[i].first - cur, 0LL);
    cur += add;
    ext += add;
    cur += pp[i].second - pp[i].first;
  }
  cout << ext << endl;
  return 0;
}