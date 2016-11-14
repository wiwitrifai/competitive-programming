#include <bits/stdc++.h>

using namespace std;

set < string > st;
string create(string s, int num) {
  if (num < 0)
    return s;
  if (num == 0)
    s.push_back('0');
  int k = 1;
  while (num >= k) k *= 10;
  while (k > 1) {
    k /= 10;
    s.push_back((num/k) + '0');
    num %= k;
  }
  return s;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int i = -1; ; i++) {
      string str = create(s, i);
      if (!st.count(str)) {
        cout << str << endl;
        st.insert(str);
        break;
      }
    }
  }
  return 0;
}