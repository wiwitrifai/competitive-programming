#include <bits/stdc++.h>

using namespace std;

const int N = 61;
map< long long, int > mp[N];
int grund(int val, long long mask) {
  if (val == 0)
    return 0;
  mask &= (1LL<<(val+1)) - 1;
  if (mp[val].count(mask))
    return mp[val][mask];
  set< int > st;
  for (int i = 1; i <= val; i++)
    if (((1LL<<i) & mask) == 0)
      st.insert(grund(val-i, (mask | (1LL<<i))));
  int ans = 0;
  for (int it : st)
    ans += it == ans;
  mp[val][mask] = ans;
  return ans;
}

int g[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
int main() {
  // for (int i = 0; i < N; i++)
  //   cout << grund(i, 0) << ", "; 
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);
    ans ^= g[s];
  } 
  puts(ans ? "NO" : "YES");
  return 0;
}