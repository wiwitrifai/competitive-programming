#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  vector< int > live;
  vector< pair< int, int  > > ans;
  for (int i = n-1; i >= 0; i--) {
    if (a[i] > live.size()) {
      puts("NO");
      return 0;
    } 
    else {
      for (int j = 0; j < a[i]; j++) {
        ans.emplace_back(i+1, live.back()+1);
        live.pop_back();
      }
    }
    live.push_back(i);
  }
  puts("YES");
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}