#include <bits/stdc++.h>

using namespace std;

int a[15];

int main() {
  int n;
  scanf("%d", &n);
  map < pair< int, int >, int > st;
  for (int i = 0; i < (1<<n); i++) {
    int c, b;
    c = b = 0;
    for (int j = 0; j < n; j++) {
      a[j] = (i>>j) & 1;
    }
    a[n] = a[0];
    a[n+1] = a[1];
    for (int j = 1; j <= n; j++) {
      b += (a[j-1] == 0) && (a[j+1] == 0);
      c += (a[j-1] == 1) && (a[j+1] == 1);
    }
    if (b > c)
      continue;
    if (st.count(make_pair(b, c)))
      continue;
    st[make_pair(b, c)] = i;
  }
  for (auto it : st) {
    cout << it.first.first << " " << it.first.second << endl;
    for (int j = 0; j < n; j++)
      if (it.second & (1<<j))
        printf("1");
      else
        printf("0");
    printf("\n");
  }
  cerr << st.size() << endl;
  return 0;
}