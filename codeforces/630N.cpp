#include <bits/stdc++.h>

using namespace std;

int main() {
  long double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(20);
  long double ans1 = (-b + sqrt(b*b-4*a*c))/(2*a),
  ans2 = (-b - sqrt(b*b-4*a*c))/(2*a);
  if(ans1 < ans2)
    swap(ans1, ans2);
  cout << ans1 << endl;
  cout << ans2 << endl;
  return 0;
}