#include <bits/stdc++.h>

using namespace std;

const int N = 106;

int a[N];
int b[N];
string name[N];

int main() {
  for (int i = 0; i < 26; i++) {
    name[i] = "Aa";
    name[i][1] += i;
  }
  for (int i = 0; i < 26; i++) {
    name[26 + i] = "Ba";
    name[26 + i][1] += i;
  }
  int n, k;
  scanf("%d %d", &n, &k);
  k--;
  for (int i = 0; i < n-k; i++){
    string s;
    cin >> s;
    b[i] = (s[0] == 'Y');
  }
  for (int i = 0; i < k; i++)
    a[i] = i;
  for (int i = k; i < n; i++)
    if (b[i-k]) {
      set < int > st;
      for (int j = i-k; j < i; j++)
        st.insert(a[j]);
      a[i] = 0;
      for (int x : st)
        a[i] += x == a[i];
    }
    else
      a[i] = a[i-k];
  for (int i = 0; i < n; i++)
    cout << name[a[i]] << "\n";
  return 0;
}