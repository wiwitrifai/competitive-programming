#include <bits/stdc++.h>

using namespace std;
const int MAXCHAR = 1e6 + 5;

typedef long long LL;
const int INF = 1e9;

typedef pair<LL,int> pli;
typedef pair<LL,bool> plb;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const LL MOD = 252097800623LL;
const LL MULT = 29;

bool befcomma[MAXCHAR];
bool aftcomma[MAXCHAR];
bool End[MAXCHAR];
bool Start[MAXCHAR];
LL hashes[MAXCHAR];
pli hashsort[MAXCHAR];

map<LL, bool> MAPBEF;
map<LL, bool> MAPAFT;

string s;

int n;

queue<pli> q;

vector<string> split(const string &s){
  stringstream ss(s);
  vector<string> ans;
  string buf;
  while(ss >> buf){
    ans.push_back(buf);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  getline(cin, s);
  vector<string> v = split(s);
  n = (int) v.size();
  
  fprintf(stderr, "SIZE : %d\n", n);
  bool starts = 1;
  for(int i = 0;i < n; ++i){
    Start[i] = starts;
    starts = 0;
    const string &now = v[i];
    char belakang = now[now.length() - 1];
    LL hashnow = 0;
    if(belakang == ',' || belakang == '.'){
      for(int j = 0;j < (int) now.length() - 1; ++j){
        hashnow *= MULT;
        hashnow += now[j] - 'a' + 1;
        hashnow %= MOD;
      }
      if(belakang == '.') {
        End[i] = 1;
        starts = 1;
      }
      else if(belakang == ','){
        aftcomma[i] = 1;
        befcomma[i + 1] = 1;
      }
    }
    else{
      for(int j = 0;j < (int) now.length(); ++j){
        hashnow *= MULT;
        hashnow += now[j] - 'a' + 1;
        hashnow %= MOD;
      }
    }
    hashes[i] = hashnow;
    hashsort[i] = mp(hashnow, i);
    //fprintf(stderr, "HASH %d: %lld\n", i, hashes[i]);
  }
  sort(hashsort, hashsort + n);
  for(int i = 0;i < n; ++i){
    if(aftcomma[i]) {
      if(!MAPAFT.count(hashes[i])){
        q.push(mp(hashes[i], 1));
        MAPAFT[hashes[i]] = 1;
      }
    }
    
    if(befcomma[i]) {
      if(!MAPBEF.count(hashes[i])){
        q.push(mp(hashes[i], 0));
        MAPBEF[hashes[i]] = 1;
      }  
    }
  }
  while(!q.empty()){
    pli now = q.front(); q.pop();
    int lo = lower_bound(hashsort, hashsort + n, mp(now.fi, -1)) - hashsort;
    int hi = upper_bound(hashsort, hashsort + n, mp(now.fi, INF)) - hashsort;
    //fprintf(stderr, "NOW : (%lld,%d): %d %d\n", now.fi, now.se, lo, hi);
    
    if(now.se == 0){
      for(int i = lo;i < hi; ++i){
        int idx = hashsort[i].se;
        if(Start[idx]) continue;
        befcomma[idx] = 1;
        if(!MAPAFT.count(hashes[idx - 1])){
          MAPAFT[hashes[idx - 1]] = 1;
          q.push(mp(hashes[idx - 1], 1));
        }
      }
    }
    else{
      for(int i = lo;i < hi; ++i){
        int idx = hashsort[i].se;
        if(End[idx]) continue;
        aftcomma[idx] = 1;
        if(!MAPBEF.count(hashes[idx + 1])){
          MAPBEF[hashes[idx + 1]] = 1;
          q.push(mp(hashes[idx + 1], 0));
        }
      }
    }
  }
  for(int i = 0;i < n; ++i){
    if(i) cout << " ";
    cout << v[i];
    char last = v[i][v[i].length() - 1];
    if(last != ',' && aftcomma[i]) cout << ",";
  }
  cout << endl;
  
  return 0;
}
