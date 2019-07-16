// By Radit

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const LL INFL = 1e15;
const double PI = acos(-1);
const int N = 1e5;

int main(){
  int n;
  scanf("%d", &n);
  int res = 0;
  for(int i = 0;i < n; ++i){
    char c[10];
    scanf("%s", c);
    if(c[0] == 'L') res ^= 1;
  }

  if(res == 0) puts("TRUTH");
  else puts("LIE");

  return 0;
} 