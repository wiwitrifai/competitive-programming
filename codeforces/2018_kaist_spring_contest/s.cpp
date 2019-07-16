#include <bits/stdc++.h>

using namespace std;

map<string, int> cnt, recent;

int r[5], f[5];
string mat[5][5] = {{"New Customer", "Promising", "About to Sleep", "Lost", "Lost"}, 
                    {"Potential Loyalist", "Potential Loyalist", "About to Sleep", "Hibernating", "Lost"},
                    {"Potential Loyalist", "Potential Loyalist", "Need Attention", "About to Leave", "About to Leave"}, 
                    {"Loyal Customer", "Loyal Customer", "Loyal Customer", "About to Leave", "About to Leave"},
                    {"Champion", "Loyal Customer", "Loyal Customer", "About to Leave", "Can't Lose Them"}};

string none = "None";
char name[20];

int main() {
  for (int i = 0; i < 4; ++i)
    scanf("%d", r+i);
  for (int i = 0; i < 4; ++i)
    scanf("%d", f+i);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d %s", &a, name);
    string sname = name;
    if (a == 1) {
      ++cnt[sname];
      recent[sname] = i;
    }
    else {
      auto it = cnt.find(sname);
      if (it == cnt.end()) {
        puts(none.c_str());
        continue;
      }
      int cf = it->second, cr = i - recent[sname];
      int pf = lower_bound(f, f+4, cf) - f;
      int pr = lower_bound(r, r+4, cr) - r;
      puts(mat[pf][pr].c_str());
    }
  }
  return 0;
}
