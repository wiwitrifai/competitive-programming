#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 505;
 
bool done[N][N * N];
 
int solve(vector<int> a) {
  if(a.empty()) return 0;
  int sum = 0;
  for(auto it : a) sum += it;
  memset(done, 0, sizeof(done));
  done[0][a[0]] = 1;
  for(int i = 1; i < a.size(); i++) {
    for(int j = 0; j <= sum; j++) {
      if(done[i - 1][j]) {
        if(j + a[i] < N * N) {
          done[i][j + a[i]] = 1;
        }
        done[i][abs(j - a[i])] = 1;
      }
    }
    if(done[i][sum / 2]) {
      return sum % 2;
    }
  }
  for(int i = 0; i < N * N; i++) {
    if(done[a.size() - 1][i]) {
      return i;
    }
  }
  assert(0);
}
 
int a[N];
 
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
      char c;
      if(i) scanf(" %c", &c);
      scanf("%d", a + i);
    }
    vector<int> odd, even;
    for(int i = 0; i <= n; i++) {
      if(i % 2) odd.push_back(a[i]);
      else even.push_back(a[i]); 
    }
    int ans = solve(odd) + solve(even);
    printf("%d\n", ans);
  }
  return 0;
} 