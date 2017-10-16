#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5;
int arr[N + 5];
LL pref[N + 5];
int d, n = 1;
int dim[N + 5];
int kali[N + 5];

vector<int> conv_to_dims(int x){
  vector<int> v;
  int temp = x;
  for(int i = 0;i < d; ++i){
    v.push_back(temp / kali[i]);
    temp %= kali[i];    
  }
  return v;  
}

int conv_to_int(const vector<int> v){
  int ans = 0;
  for(int i = 0;i < d; ++i) ans += v[i] * kali[i];
  return ans;
}

int main(){
  scanf("%d", &d);
  for(int i = 0;i < d; ++i) scanf("%d", &dim[i]), n *= dim[i];
  kali[d-1] = 1;
  for(int i = d - 2;i >= 0; --i) kali[i] = kali[i + 1] * dim[i + 1];
  for(int i = 0;i < n; ++i) {
    scanf("%d", &arr[i]);
    vector<int> dims = conv_to_dims(i);
    pref[i] = arr[i];
    for(int j = 1;j < (1 << d); ++j){

      LL mult;
      if(__builtin_popcount(j) & 1) mult = 1;
      else mult = -1;
      vector<int> dims2 = dims;
      bool minus = false;
      for(int k = 0;k < d; ++k){
        if((1 << k) & j) dims2[k]--;
        if(dims2[k] < 0) minus = true;
      }
      if(minus) continue;
      pref[i] += mult * pref[conv_to_int(dims2)];
    }
  }
  int q;
  scanf("%d", &q);
  while(q--){
    vector<int> l(d);
    vector<int> r(d);
    for(int i = 0;i < d; ++i) scanf("%d", &l[i]), l[i]--;
    for(int i = 0;i < d; ++i) scanf("%d", &r[i]), r[i]--;
    LL ans = 0;
    for(int i = 0;i < (1 << d); ++i){
      vector<int> v;
      bool minus = false;
      for(int j = 0;j < d; ++j){
        if((1 << j) & i){
          v.push_back(l[j] - 1);
          if(l[j] == 0) minus = true;
        }
        else{
          v.push_back(r[j]);
        }
      }
      if(minus) continue;
      else{
        LL kali = __builtin_popcount(i) & 1 ? -1LL : 1LL;
        ans += kali * pref[conv_to_int(v)];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}