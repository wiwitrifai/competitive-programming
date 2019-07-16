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
const int INF = 1e9;
const double PI = acos(-1);
const int N = 2e3, M = 1e4;


string s, ss;

char message[M + 5];

int dist[N + 5][N + 5];
int len;

int rek(int posa, int posb){
  if(posa == len) return len - posb;
  if(posb == len) return len - posa;
  if(dist[posa][posb] != -1) return dist[posa][posb];
  int &ret = dist[posa][posb] = INF;
  ret = min(ret, rek(posa, posb + 1) + 1);
  ret = min(ret, rek(posa + 1, posb) + 1);
  if(s[posa] == ss[posb]) ret = min(ret, rek(posa + 1, posb + 1));
  else ret = min(ret, rek(posa + 1, posb + 1) + 1);
  return ret;
}

int main(){
  // s = "";
  // for(int i = 0;i < 10; ++i) s += "01";
  // for(int xxx = 0;xxx < 10; ++xxx){
  //   random_shuffle(s.begin(), s.end());
  //   len = (int) s.size();
  //   ss = "";
  //   puts(s.c_str());
    int cnt0 = 0, cnt1 = 0;
    cin >> s;
    for(int i = 0;i < (int) s.size(); ++i){
      if(s[i] == '0') cnt0++;
      else cnt1++;
    }
    char c = '2';
    if(cnt0 > cnt1) c = '1';
    else if(cnt0 < cnt1) c = '0';
    if(c != '2'){
      for(int i = 0;i < (int) s.size(); ++i){
        ss += c;
      }
      puts(ss.c_str());
    }
    else{
      for(int i = 0;i < (int) s.size(); ++i) ss += s[0];
      if(s[0] == '1') ss[0] = '0';
      else ss[0] = '1';
      puts(ss.c_str());
    }
    // sprintf(message, "./dist %s %s", s.c_str(), ss.c_str());
    // std::system(message);

  
  return 0;
} 

/*
  00110011011110001010
  11011111111111111111
*/