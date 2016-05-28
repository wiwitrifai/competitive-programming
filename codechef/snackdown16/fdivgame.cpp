#include <bits/stdc++.h>

using namespace std;

int find(long long a) {
  if(a <= 0) return 0;
  if(a <= 1) return 1;
  if(a <= 3) return 2;
  if(a <= 5) return 3;
  if(a <= 11) return 0;
  long long bef = 1;
  while(bef * 12 <= a) bef *= 12;
  int t = a / bef;
  if(t <= 1) return 1;
  if(t <= 3) return 2;
  if(t <= 5) return 3;
  return 0;
}


int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      long long num;
      scanf("%lld", &num);
      ans ^= find(num);
    }
    puts(ans? "Henry" : "Derek");
  }
  return 0;
}