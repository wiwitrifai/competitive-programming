#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const double PI = acos(-1.);

#define double long double

double a[N];

int main() {
  int r;
  cin >> r;
  for (int i = 0; i < 26; i++) {
    char c;
    double v;
    cin >> c >> v;
    a[c - 'A'] = v;
  }
  cin.ignore();
  string str;
  getline(cin, str);
  //cout << str << endl;
  double ans = 0;
  int p = -1;
  for (int i = 0; i < str.size(); i++) {
    int c = -1;
    if ('a' <= str[i] && str[i] <= 'z') {
      c = str[i] - 'a';
    } else if ('A' <= str[i] && str[i] <= 'Z') {
      c = str[i] - 'A';
    } else {
      continue;
    }
    if (p == -1) {
      ans += r;
    } else {
      double teta = abs(a[c] - a[p]);
      teta = min(teta, 360 - teta);
      teta = teta * PI / 180;
      double d = r * sqrt(2 * (1 - cos(teta)));
      ans += d;
    }
    p = c;
  }
  printf("%lld\n", (long long) (ceil(ans) + 0.5));
  return 0;
}
