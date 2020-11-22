#include <bits/stdc++.h>

using namespace std;

vector<int> hidden;

int qand(int i, int j) {
#ifdef LOCAL
  return hidden[i] & hidden[j];
#endif

  ++i, ++j;
  printf("AND %d %d\n", i, j);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  if (x == -1)
    exit(0);
  return x;
}

int qor(int i, int j) {
#ifdef LOCAL
  return hidden[i] | hidden[j];
#endif

  ++i, ++j;
  printf("OR %d %d\n", i, j);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  if (x == -1)
    exit(0);
  return x;
}

int qxor(int i, int j) {
#ifdef LOCAL
  return hidden[i] ^ hidden[j];
#endif

  ++i, ++j;
  printf("XOR %d %d\n", i, j);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  if (x == -1)
    exit(0);
  return x;
}


int main() {
  int n;
  scanf("%d", &n);
#ifdef LOCAL
  hidden.resize(n);
  // for (int i = 0; i < n; ++i)
  //   hidden[i] = rand() % n;
  iota(hidden.begin(), hidden.end(), 0);
  random_shuffle(hidden.begin(), hidden.end());
#endif
  vector<int> a(n, 0);
  for (int i = 1; i < n; ++i) {
    a[i] = qxor(0, i);
  }
  vector<int> b(n, -1);
  int duplicate = -1;
  for (int i = 0; i < n; ++i) {
    if (b[a[i]] != -1) {
      duplicate = i;
      break;
    }
    b[a[i]] = i;
  }
  if (duplicate != -1) {
    int res = qand(b[a[duplicate]], duplicate);
    vector<int> c = a;
    for (int i = 0; i < n; ++i) {
      a[i] = c[i]^c[duplicate]^res;
    }
  } else {
    int s1 = -1, s2 = -1;
    for (int i = 1; i < n; ++i) {
      if (a[i] == n-1) continue;
      s1 = i;
    }
    for (int i = 1; i < n; ++i) {
      if (i == s1) continue;
      if ((a[i] != ((n-1)^a[s1]))) continue;
      s2 = i;
    }
    int bits = 0;
    while ((1 << bits) < n) ++bits;
    int r1 = qand(0, s1);
    int r2 = qand(0, s2);
    for (int i = 0; i < bits; ++i) {
      if ((a[s1] & (1 << i)) == 0) {
        if (r1 & (1 << i))
          a[0] |= 1 << i;
      } else {
        if (r2 & (1 << i))
          a[0] |= 1 << i;
      }
    }
    for (int i = 1; i < n; ++i)
      a[i] ^= a[0];
  }
  printf("!");
  for (int i = 0; i < n; ++i)
    printf(" %d", a[i]);
  printf("\n");
  fflush(stdout);
#ifdef LOCAL
  for (int i = 0; i < n; ++i)
    cerr << hidden[i] << " ";
  cerr << endl;
  for (int i = 0; i < n; ++i)
    cerr << a[i] << " ";
  cerr << endl;
  assert(hidden == a);
#endif
  return 0;
}
