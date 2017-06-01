#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    bool ok = true
    memset(ans, -1, sizeof ans);
    for(int i = 0; i<n && ok; i++) if(ans[i] == -1) {
      ans[i] = i+k+1;
      ans[i+k] = i+1;
    }
    if(ok) {
      for(int i = 0; i<n; i++)
        printf("%d ", ans[i]);
      puts("");
    }
    else
      puts("-1");
  }
  
  return 0;
}