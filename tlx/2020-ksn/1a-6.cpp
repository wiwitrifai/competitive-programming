#include <bits/stdc++.h>

using namespace std;

vector<int> xa, xb, ya, yb;

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> a(k);
  xa.assign(k, -1);
  xb.assign(k, -1);
  ya.assign(k, -1);
  yb.assign(k, -1);
  assert(n == 2);
  vector<int> odd, even;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
    if (a[i] & 1)
      odd.push_back(i);
    else
      even.push_back(i);
  }
  assert(odd.size() == 10);
  assert(even.size() == 10);
  map<int, int> mp;
  for (int mask = 0; mask < 1024; ++mask) {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
      if (mask & (1 << i))
        sum += a[odd[i]];
      else
        sum -= a[odd[i]];
    }
    mp[sum] = mask;
  }
  vector<int> side(k, -1);
  bool found = false;
  for (int maska = 0; maska < 1024 && !found; ++maska) {
    int other = 1023 ^ maska;
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
      if (maska & (1 << i))
        sum += a[even[i]];
    }
    for (int maskb = other; !found; maskb = (maskb - 1) & other) {
      int cur = sum;
      for (int i = 0; i < 10; ++i) {
        if (maskb & (1 << i))
          cur -= a[even[i]];
      }
      if (mp.find(cur) != mp.end()) {
        found = true;
        for (int i = 0; i < 10; ++i) {
          if (maska & (1 << i)) {
            side[even[i]] = 1;
          } else if (maskb & (1 << i)) {
            side[even[i]] = 2;
          }
          else {
            side[even[i]] = 3;
          }
        }
        int mask = mp[cur];
        cerr << maska << " " << maskb << " " << mask << endl;
        for (int i = 0; i < 10; ++i) {
          if (mask & (1 << i)) {
            side[odd[i]] = 2;
          }
          else {
            side[odd[i]] = 1;
          }
        }
      }
      if (maskb == 0)
        break;
    }
  }
  cerr << found << endl;
  int low = 0;
  for (int i = 0; i < k; ++i) {
    if (side[i] == 3) {
      assert((a[i] & 1) == 0);
      xa[i] = 0;
      xb[i] = 2;
      ya[i] = low;
      yb[i] = low + a[i] / 2;
      low += a[i] / 2;
    }
  }
  for (int s = 1; s <= 2; ++s) {
    int from = low;
    for (int i = 0; i < k; ++i) {
      if (side[i] == s) {
        xa[i] = s - 1;
        xb[i] = s;
        ya[i] = from;
        yb[i] = from + a[i];
        from += a[i];
      }
    }
    assert(from == m);
  }
  for (int i = 0; i < k; ++i) {
    if (xa[i] > xb[i]) {
      swap(xa[i], xb[i]);
    }
    if (ya[i] > yb[i]) {
      swap(ya[i], yb[i]);
    }
    printf("%d %d %d %d\n", xa[i], xb[i], ya[i], yb[i]);
  }
  return 0;
}
