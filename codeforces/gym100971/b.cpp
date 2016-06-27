#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], n;
vector< pair< int, int > > ans; 

int main() {
  scanf("%d", &n);
  int bef = -1;
  for(int i = 1; i<=n; i++)
    scanf("%d", a+i);

  for(int i = 1; i<=n; i++) {
    if(a[i] == i) {
      if(bef == -1)
        bef = i;
      else {
        swap(a[bef], a[i]);
        ans.push_back({bef, i});
        bef = -1;
      }
    }
  }
  if(bef != -1) {
    int z = 1;
    if(bef == z)
      z++;
    ans.push_back({z, bef});
  }
  printf("%d\n", ans.size());
  for(int i = 0; i<ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}