#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 1000;
const int INF = 1e9;
const LL INFL = 1e15;

int a,b,k;

vector<char> ve;
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d%d%d", &a, &b, &k);
    if(b > a){
      if((b - 1) / k > a) {
        puts("mustahil");
        continue;
      }
      else{
        int cnta = 0, cntb = 0;
        for(int i = 0;i < a + b && cnta <= a && cntb <= b; ++i){
          if(((i + 1) % (k + 1)) == 0) {
            if(cnta == a) break;
            ve.push_back('L'), cnta++;
          }
          else {
            if(cntb == b) break;
            ve.push_back('P'), cntb++;
          }
        }

        if(cnta != a){
          for(int i = cnta; i < a; ++i){
            for(int j = 0;j < ve.size(); ++j){
              if(ve[j] == 'P' && j == 0){
                ve.insert(ve.begin() + j, 'L');
                break;
              }
              else if(ve[j] == 'P' && ve[j - 1] == 'P'){
                ve.insert(ve.begin() + j, 'L');
                break; 
              }
            }
          }
        }
      }
    }
    else{
      if((a - 1) / 2 > b){
        puts("mustahil");
        continue;
      }
      else{
        int cnta = 0, cntb = 0;
        for(int i = 0;i < a + b && cnta <= a && cntb <= b; ++i){
          if(((i + 1) % 3) == 0) {
            if(cntb == b) break;
            ve.push_back('P'), cntb++;
          }
          else {
            if(cnta == a) break;
            ve.push_back('L'), cnta++;
          }
        }
        if(cntb != b){
          for(int i = cntb; i < b; ++i){
            for(int j = 0;j < ve.size(); ++j){
              if(ve[j] == 'L' && j == 0){
                ve.insert(ve.begin() + j, 'P');
                break;
              }
              else if(ve[j] == 'L' && ve[j - 1] == 'L'){
                ve.insert(ve.begin() + j, 'P');
                break; 
              }
            }
          }
        }
      }
    }
    for(int i = 0;i < ve.size(); ++i) printf("%c", ve[i]);
    puts("");
    ve.clear();
  }

  return 0;
}