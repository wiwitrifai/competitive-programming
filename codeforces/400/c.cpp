#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<  long long > val;
  if (k == -1 || k == 1) {
    val.push_back(k);
    val.push_back(k * k);
  }
  else {
    long long now = 1;
    while (abs(now) < 1e17) {
      val.push_back(now);
      now *= k;
    }
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  map < long long, int > mp;
  long long now = 0;
  mp[now] = 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    now += a[i];
    for (long long v : val) {
      if (mp.count(now - v))
        ans += mp[now-v];
    }
    mp[now]++;
  }
  cout << ans << endl;
  return 0;
}