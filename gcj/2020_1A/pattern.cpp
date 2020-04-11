#include <bits/stdc++.h>

using namespace std;

char buffer[1024];

vector<string> split(string& p) {
  vector<string> ret;
  string cur = "";
  for (int i = 0; i < (int)p.size(); ++i) {
    if (p[i] == '*') {
      if (!cur.empty())
        ret.push_back(cur);
      cur = "";
    }
    else {
      cur.push_back(p[i]);
    }
  }
  if (!cur.empty())
    ret.push_back(cur);
  return ret;
}

bool match(string& s, string& p) {
  vector<string> vp = split(p);
  int i = 0;
  for (string& x : vp) {
    bool ok = false;
    while ((int)s.size()-i >= (int)x.size()) {
      if (s.substr(i, x.size()) == x) {
        ok = 1;
        i += x.size();
        break;
      }
      ++i;
    }
    if (!ok)
      return false;
  }
  return true;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<string> vs;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    vs.push_back(buffer);
  }
  string ans = "";
  for (string& s : vs) {
    int cnt = 0;
    for (char c : s) {
      cnt += c == '*';
    }
    if (cnt == 0)
      ans = s;
  }
  if (!ans.empty()) {
    for (string& s : vs) {
      if (!match(ans, s)) {
        puts("*");
        return;
      }
    }
    printf("%s\n", ans.c_str());
    return;
  }
  string pre = "", suf = "";
  for (auto s : vs) {
    vector<string> vp = split(s);
    if (vp.empty()) continue;
    int l = 0, r = (int)vp.size()-1;
    if (s[0] != '*') {
      int len = min(pre.size(), vp[0].size());
      if (pre.substr(0, len) != vp[0].substr(0, len)) {
        puts("*");
        return;
      }
      if (vp[0].size() > pre.size())
        pre = vp[0];
      ++l;
    }
    if (s.back() != '*') {
      int len = min(suf.size(), vp.back().size());
      string& vpb = vp.back();
      if (len > 0 && suf.substr((int)suf.size()-len, len) != vpb.substr((int)vpb.size() - len, len)) {
        puts("*");
        return;
      }
      if (vpb.size() > suf.size())
        suf = vpb;
      --r;
    }
    while (l <= r) {
      ans += vp[l++];
    }
  }
  ans = pre + ans + suf;
  printf("%s\n", ans.c_str());
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
