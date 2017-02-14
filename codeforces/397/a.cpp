#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

string s[N], h;
map< string, int > mp;
bool vis[N], back[N];

int main() {
  memset(vis, 0, sizeof vis);
  memset(back, 0, sizeof back);
  int n;
  cin >> n;
  puts(n & 1 ? "contest" : "home");
  return 0;
  cin >> h;
  int node = 0;
  mp[h] = node++;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    string a, b;
    a = s[i].substr(0, 3);
    b = s[i].substr(5, 3);
    if (!mp.count(a)) mp[a] = node++;
    if (!mp.count(b)) mp[b] = node++;
    if (a == h)
      vis[mp[b]] = 1;
    if (b == h)
      back[mp[a]] = 1;
  }
  bool home = 1;
  for (int i = 1; i < node; i++) {
    if (vis[i] && !back[i])
      home = 0;
  }
  puts(home ? "home" : "contest");
  return 0;
}