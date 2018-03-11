// by radit
#include <bits/stdc++.h>

using namespace std;
typedef pair<string, int> psi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const string filename = "abbreviation";

const int N = 1000;
char ar[N + 5];

bool capital(const string& s){
  if(s.size() < 2) return false;
  if(!isupper(s[0])) return false;
  for(int i = 1;i < (int) s.size(); ++i) if(!islower(s[i])) return false;
  return true;
}

string abbr(vector<string>& v){
  string ans = "";
  for(int i = 0;i < (int) v.size(); ++i){
    ans += v[i][0];
  }
  ans += " (";
  for(int i = 0;i < (int) v.size(); ++i){
    ans += v[i];
    if(i != (int)v.size() - 1) ans += " ";
    else ans += ")";
  }
  return ans;
}

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif

  while(gets(ar)){
    int len = strlen(ar);
    vector<psi> words;
    string s = "";
    int idxnow = 0;
    string wordnow = "";
    for(int i = 0;i < len; ++i){
      if(ar[i] == '.' || ar[i] == ','){
        if(wordnow != "") words.push_back(mp(wordnow, idxnow));
        wordnow = "";
        idxnow = i + 1;
        string cur = "";
        cur += ar[i];
        words.push_back(mp(cur, idxnow - 1));
      }
      else if(ar[i] == ' '){
        if(wordnow != "") words.push_back(mp(wordnow, idxnow));
        wordnow = "";
        idxnow = i + 1;
      }
      else{
        wordnow += ar[i];
      }
    }
    if(wordnow != "") words.push_back(mp(wordnow, idxnow));
    vector<string> v;
    // fprintf(stderr, "DEBUG\n");
    // for(int i = 0;i < (int)words.size(); ++i){
    //   fprintf(stderr, "%s %d\n", words[i].fi.c_str(), words[i].se);
    // } 
    for(int i = 0;i < (int)words.size(); ++i){
      if(!capital(words[i].fi)){

        if((int) v.size() >= 2){
          string res = abbr(v);
          v.clear();
          s += res; 
        }
        else if((int) v.size() == 1) {
          s += v[0];
          v.clear();
        }
        int banyak = 0;
        if(i){
          banyak = words[i].se - (words[i - 1].se + (int)words[i - 1].fi.length());
        }
        for(int j = 0;j < banyak; ++j) s += " ";
        s += words[i].fi;
      }
      else{
        if(v.size() == 0) {
          int banyak = 0;
          if(i){
            banyak = words[i].se - (words[i - 1].se + (int)words[i - 1].fi.length());
          }
          for(int j = 0;j < banyak; ++j) s += " ";
          v.push_back(words[i].fi);
        } 
        else {
          int siz = words[i].se - (words[i - 1].se + (int) words[i - 1].fi.length());
          if(siz == 1) v.push_back(words[i].fi);
          else{
            if((int) v.size() >= 2){
              string res = abbr(v);
              v.clear();
              s += res;
            }
            else if((int) v.size() == 1){
              s += v[0];
              v.clear();
            }
            int banyak = 0;
            if(i){
              banyak = words[i].se - (words[i - 1].se + (int)words[i - 1].fi.length());
            }
            for(int j = 0;j < banyak; ++j) s += " ";
            v.push_back(words[i].fi);
          } 
        }
      }
    }
    if(v.size() >= 2){
      string res = abbr(v);
      v.clear();
      s += res;
    }
    else if((int) v.size() == 1){
      s += v[0];
      v.clear();
    }
    puts(s.c_str());
  }
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  return 0;
}