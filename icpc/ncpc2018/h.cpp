#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7, week = 10080;

char buf[100];

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int l, m;
  scanf("%d %d\n", &l, &m);
  vector<string> ans;
  int best = inf;
  for (int i = 0; i < m; ++i) {
    int p, c, t, r;
    scanf("%[^,],%d,%d,%d,%d\n", buf, &p, &c, &t, &r); 
    // cerr << buf << "|" << p << " " << c << " " << t << " " << r << endl;
    if (p > best)
      continue;
    bool ok = 1;
    int sum = t + r;
    int k = sum / gcd(sum, week);
    int z = week / gcd(sum, week);
    long long kerja = 1LL * c * t * z, butuh = 1LL * l * k;
    if (kerja < butuh)
      continue;
    if (best > p) {
      best = p;
      ans.clear();
    }
    if (best == p)
      ans.push_back(buf);
  }
  if (ans.empty())
    printf("no such mower\n");
  else {
    for (auto s : ans)
      printf("%s\n", s.c_str());
  }
  return 0;
}