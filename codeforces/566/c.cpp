#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, L = 1e6 + 6;

char cvow[] = "aiueo";

bool isvowel(char c) {
  for (int i = 0; i < 5; ++i)
    if (cvow[i] == c)
      return true;
  return false;
}

string str[N];
int match[N];
int cnt[N];
char last[N];

char buff[L];
int ada[L][26];

int main() {
  int n;
  scanf("%d", &n);
  memset(ada, -1, sizeof ada);
  vector<pair<int, int> > fir, sec;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buff);
    str[i] = buff;
    cnt[i] = 0;
    for (char c : str[i]) {
      if (!isvowel(c)) continue;
      ++cnt[i];
      last[i] = c;
    }
    int cand = ada[cnt[i]][last[i]-'a'];
    if (cand != -1) {
      sec.emplace_back(i, cand);
      ada[cnt[i]][last[i]-'a'] = -1;
    }
    else {
      ada[cnt[i]][last[i]-'a'] = i;
      match[i] = -1;
    }
  }
  for (int i = 1; i < L; ++i) {
    int last = -1;
    for (int j = 0; j < 26; ++j) {
      if (ada[i][j] != -1) {
        if (last != -1) {
          fir.emplace_back(last, ada[i][j]);
          last = -1;
        }
        else
          last = ada[i][j];
      }
    }
  }
  int ans = min(((int)fir.size() + (int)sec.size()) / 2, (int)sec.size());
  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    pair<int, int> le, ri;
    if (fir.size() > 0) {
      le = fir.back();
      fir.pop_back();
    }
    else {
      le = sec.back();
      sec.pop_back();
    }
    ri = sec.back();
    sec.pop_back();
    printf("%s %s\n%s %s\n", str[le.first].c_str(), str[ri.first].c_str(),
      str[le.second].c_str(), str[ri.second].c_str());
  }
  return 0;
}
