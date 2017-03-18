#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

set< pair< long long, int > > le, ri;
int l[N], r[N];


int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lld %lld", l+i, r+i);
  long long now = 0;
  int tmp = 0;
  le.insert(make_pair(l[0], tmp++));
  ri.insert(make_pair(l[0], tmp++));
  long long offl = 0, offr = 0;
  for (int i = 1; i < n; i++) {
    long long bef = r[i-1]-l[i-1], cur = r[i]-l[i];
    offl -= cur;
    offr += bef;
    long long midl = (--le.end())->first+offl, midr = ri.begin()->first+offr;
    if (l[i] < midl) {
      le.insert(make_pair(l[i]-offl, tmp++));
      le.insert(make_pair(l[i]-offl, tmp++));
      auto it = --le.end();
      ri.insert(make_pair(midl-offr, tmp++));
      le.erase(it);
      now += midl-l[i];
    }
    else if (l[i] > midr) {
      ri.insert(make_pair(l[i]-offr, tmp++));
      ri.insert(make_pair(l[i]-offr, tmp++));
      auto it = ri.begin();
      le.insert(make_pair(midr-offl, tmp++));
      ri.erase(it);
      now += l[i] - midr;
    }
    else {
      le.insert(make_pair(l[i]-offl, tmp++));
      ri.insert(make_pair(l[i]-offr, tmp++));
    }
  }
  cout << now << endl;
  return 0;
}