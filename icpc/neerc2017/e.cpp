// by radit
#include <bits/stdc++.h>

using namespace std;
const int N = 1000;
int ar[N + 5];
vector<int> ans;
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for(int i = 0;i < n; ++i){
    int x;
    scanf("%d", &x);
    if(x > 0){
      ar[x]++;
    }
    else if(x == 0){
      cnt++;
    }
    else{
      if(ar[-x] == 0){
        if(cnt == 0){
          puts("No");
          return 0;
        }
        else{
          ans.push_back(-x);
          cnt--;
        }
      }
      else{
        ar[-x]--;
      }
    }
  }
  for(int i = 0;i < cnt; ++i) ans.push_back(1);
  puts("Yes");
  for(int i = 0;i < (int) ans.size(); ++i){
    if(i) printf(" ");
    printf("%d", ans[i]);

  }
  puts("");

  return 0;
}