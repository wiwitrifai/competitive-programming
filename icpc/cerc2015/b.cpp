#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a, b;
int n;

string ar;
vector<int> len;
vector<int> preflen;

int main() {
  getline(cin, ar);
  cin >> a >> b;
  n = ar.length();
  int lennow = 0;
  for(int i = 0;i < n; ++i){
    if(ar[i] != ' ') lennow++;
    else{
      len.push_back(lennow);
      lennow = 0;
    }
  }
  if(lennow) len.push_back(lennow), lennow = 0;
  int pref = -1;
  for(int i = 0;i < len.size(); ++i){
    ++pref;
    pref += len[i];
    preflen.push_back(pref);
  }
  for(int i = a; i <= b; ++i){
    int total = -1;
    for(int idx = 0;idx < len.size();){
      total += len[idx] + 1;
      int up = upper_bound(preflen.begin(), preflen.end(), preflen[idx] + i - len[idx]) - preflen.begin();
      idx = up;
      // printf("%d %d\n", i, idx);
    }
    printf("%d\n", total);
  }
  return 0;
}