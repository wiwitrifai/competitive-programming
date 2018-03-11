// by luqman
#include <bits/stdc++.h>

using namespace std;
const string filename = "hard";

const int N = 100005;
const int offset = 33000;
const int MIN = -32768;
const int MAX = 32767;

int ada[N];

vector<string> split(string s) {
  vector<string> ret;
  stringstream ss(s);
  string buf;
  while (ss >> buf) {
    ret.push_back(buf);
  }
  return ret;
}

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif

  string buf;
  while (getline(cin, buf)) {
    vector<string> s = split(buf);
    if (s.size() == 8 || s.size() == 4) s.pop_back();
    if (s.size() == 7) {
      int l = atoi(s[2].c_str());
      int r = atoi(s[6].c_str());
      if (l <= r) {
        ada[l + offset]++;
        ada[r + offset + 1]--;
      }
    }
    if (s.size() == 3) {
      int x = atoi(s[2].c_str());
      if (s[1] == ">=") {
        ada[x + offset]++;
        ada[MAX + offset + 1]--;
      } else {
        ada[MIN + offset]++;
        ada[x + 1 + offset]--;
      }
    }
  }
  for (int i = 1; i < N; i++) ada[i] += ada[i-1];
  vector<string> ans; 
  for (int l = MIN + offset; l <= MAX + offset; l++) {
    if (ada[l] == 0) continue;
    int r = l;
    while (r + 1 <= MAX + offset && ada[r + 1]) r++;
    // /printf("%d %d\n", l - offset, r - offset);
    if (l == MIN + offset && r == MAX + offset) {
      puts("true");
      goto nikichan;
    }
    if (l == MIN + offset) {
      ans.push_back("x <= " + to_string(r - offset));
    } else if (r == MAX + offset) {
      ans.push_back("x >= " + to_string(l - offset));
    } else {
      ans.push_back("x >= " + to_string(l - offset) + " && x <= " + to_string(r - offset));
    }
    l = r;
  }
  if (ans.empty()) {
    puts("false");
  }
  for (int i = 0; i < ans.size(); i++) {
    printf("%s", ans[i].c_str());
    if (i + 1 < ans.size()) printf(" ||");
    printf("\n");
  }

  nikichan:;
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  return 0;
}