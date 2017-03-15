#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6, SQ = 505;
int trie[N][26], val[N], cntr;
string s[N];
int val2[N], cntr2;
int b[N];

void add(string str, int v) {
  int id = 1;
  for (int i = 0; i < str.size(); i++) {
    int c = str[i] - 'a';
    if (trie[id][c] == 0)
      trie[id][c] = ++cntr;
    id = trie[id][c];
  }
  val[id] += v;
}

int main() {
  cntr = 1;
  cntr2 = 0;
  int m, t;
  cin >> m;
  while (m--) {
    string buf;
    cin >> t >> buf;
    if (t < 3) {
      if (buf.size() < SQ)
        add(buf, t == 1 ? 1 : -1);
      else {
        val2[cntr2] += t == 1 ? 1 : -1;
        s[cntr2++] = buf;
      }
    }
    else {
      int ans = 0;
      for (int i = 0; i < buf.size(); i++) {
        int id = 1;
        for (int j = i; j < buf.size(); j++) {
          int c = buf[j] - 'a';
          if (trie[id][c] == 0)
            break;
          id = trie[id][c];
          ans += val[id];
        }
      }
      for (int z = 0; z < cntr2; z++) {
        if (val2[z] == 0) continue;
        int x = -1;
        int n = s[z].size();
        for (int i = 0; i < n; i++) {
          while (x >= 0 && s[z][i] != s[z][x]) x = b[x];
          b[i] = x;
          x++;
        }
        x = 0;
        for (int i = 0; i < buf.size(); i++) {
          while (x >= 0 && buf[i] != s[z][x]) x = b[x];
          x++;
          if (x == n) {
            ans += val2[z];
            x = b[x-1] + 1;
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;

}