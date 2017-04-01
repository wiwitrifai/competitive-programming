#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
long long n;
int q;
string s;


int main() {
  cin >> n >> q;
  int mlv = 63 - __builtin_clzll(n);
  while (q--) {
    long long now;
    cin >> now >> s;
    int lv = mlv;
    long long cur = 1LL << lv;
    stack< int > st;
    while (cur != now) {
      if (now < cur) {
        st.push(0);
        lv--;
        cur -= (1LL << lv);
      }
      else {
        st.push(1);
        lv--;
        cur += (1LL << lv);
      }
    }
    for (char c : s) {
      if (c == 'L') {
        if (lv == 0) continue;
        lv--;
        now -= (1LL<<lv);
        st.push(0);
      }
      else if (c == 'R') {
        if (lv == 0) continue;
        lv--;
        now += (1LL<<lv);
        st.push(1);
      }
      else {
        if (st.empty()) continue;
        int v = st.top(); st.pop();
        if (v)
          now -= (1LL << lv);
        else
          now += (1LL << lv);
        lv++; 
      }
    }
    cout << now << "\n";
  }
  return 0;
}