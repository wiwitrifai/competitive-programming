#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int mp[256], b[12];

struct node {
  set < int > st;
  int cnt;
  node * to[36];
  node() : cnt(-1) {
    memset(to, 0, sizeof to);
  }
  void insert(string s) {
    node * now = this;
    int m = (int)s.size() - 1;
    int cur = 0;
    int k = 1;
    for (int i = 0; i < 6 && m >= 0; i++) {
      if (s[m] <= '9' && s[m] >= '0') {
        cur = cur + (s[m] - '0') * k;
        k *= 10;
        m--;
      }
      else break;
    }
    m++;
    for (int i = 0; i < m; i++) {
      int c = mp[s[i]];
      if (!now->to[c]) {
        now->to[c] = new node();
      }
      now = now->to[c];
    }
    for (int i = m; i < s.size(); i++) {
      if (s[i] != '0' || i+1 == (int)s.size()) {
        now->st.insert(cur);
      }
      k /= 10;
      cur %= k;
      int c = mp[s[i]];
      if (!now->to[c]) {
        now->to[c] = new node();
      }
      now = now->to[c];
    }
    now->st.insert(-1);
    now->cnt++;
  }
  int get(string s) {
    node * now = this;
    int m = s.size();
    for (int i = 0; i < m; i++) {
      int c = mp[s[i]];
      if (!now->to[c])
        return -1;
      now = now->to[c];
    }
    auto it = now->st.lower_bound(now->cnt);
    while (it != now->st.end() && now->cnt == *it) it++, now->cnt++;
    return now->cnt;
  }
};

char s[N];

int main() {
  for (int i = 0; i < 10; i++)
    mp[i+'0'] = i;
  for (int i = 0; i < 26; i++)
    mp[i+'a'] = i+10;
  b[0] = 1;
  for (int i = 0; i < 8; i++)
    b[i+1] = b[i] * 10;
  int n;
  cin >> n;
  node * root = new node();
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    int num = root->get(str);
    if (num == 0)
      str.push_back('0');
    else if (num > 0) {
      int k = 1;
      while (k <= num) k *= 10;
      num %= k;
      while (k > 1) {
        k /= 10;
        int c = num/k;
        str.push_back(c+'0');
        num %= k;
      }
    }
    root->insert(str);
    cout << str << "\n";
  }
  return 0;
}