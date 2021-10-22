#include <bits/stdc++.h>


using namespace std;

void solve() {
  vector<int> cnt(3, 0);
  for (int i = 0; i < 5; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  if (cnt[1] > cnt[2]) {
    cout << "INDIA\n";
  } else if (cnt[1] < cnt[2]) {
    cout << "ENGLAND\n";
  } else {
    cout << "DRAW\n";
  }
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
