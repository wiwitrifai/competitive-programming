#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
char s[N];

int main() {
  int n, k, p;
  scanf("%d %d %d", &n, &k, &p);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  scanf("%s", s);
  int now = 0;
  k = min(k, n);
  for (int i = 0; i < k; i++)
    now += a[i];
  for (int i = 0; i < n; i++) {
    b[i] = now;
    now -= a[i];
    now += a[(i+k) % n];
    cerr << b[i] << " ";
  }
  cerr << endl;
  int off = 0;
  deque< int > dq;
  for (int i = n-k; i >= 0; i--) {
    while (!dq.empty() && dq.back() < b[i]) dq.pop_back();
    dq.push_back(b[i]);
  }
  for (int i = 0; i < p; i++) {
    if (s[i] == '?')
      printf("%d\n", dq.front());
    else {
      off--;
      if (off < 0) off += n;
      if (dq.front() == b[(off+n-k+1) % n]) dq.pop_front();
      while (!dq.empty() && dq.back() < b[off]) dq.pop_back();
      dq.push_back(b[off]);
    }
  }

  return 0;
}