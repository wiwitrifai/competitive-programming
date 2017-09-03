#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

string s;
char vocal[] = "aiueoAIUEO";

int main() {
  int n;
  scanf("%d\n", &n);
  getline(cin, s);
  int l = 0, r = n-1;
  while (l < n) {
    bool cek = 0;
    for (int i = 0; i < 10; i++)
      if (vocal[i] == s[l])
        cek = 1;
    if (cek) break;
    l++;
  }
  while (r >= l) {
    bool cek = 0;
    for (int i = 0; i < 10; i++)
      if (vocal[i] == s[r])
        cek = 1;
    if (cek) break;
    r--;
  }
  r++;
  cout << s.substr(l, r-l) << endl;
  return 0;
}