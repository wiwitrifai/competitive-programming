#include <bits/stdc++.h>

using namespace std;

vector<string> names = {"Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn" };
vector<pair<int, int>> start = {{1, 21}, {2, 20}, {3, 21}, {4, 21}, {5, 21}, {6, 22}, {7, 23}, {8, 23}, {9, 22}, {10, 23}, {11, 23}, {12, 22}};
vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void solve() {
  int d;
  string m;
  cin >> d >> m;
  int mm = -1;
  for (int i = 0; i < (int)month.size(); ++i) {
    if (m == month[i]) {
      mm = i+1;
    }
  }
  assert(mm != -1);
  pair<int, int> cur = {mm, d};
  for (int i = 0; i < 11; ++i) {
    if (start[i] <= cur && cur < start[i+1]) {
      cout << names[i] << "\n";
      return;
    }
  }
  cout << names.back() << "\n";
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
