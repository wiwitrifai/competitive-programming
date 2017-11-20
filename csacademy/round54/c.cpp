#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int n, k;
  set<pair<int, int> > st;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 0, j = 0; i < n; i++) {
    while (j <= i+k && j < n) {
      st.insert(make_pair(a[j], -j));
      j++;
    }
    auto it = st.begin();
    if (it->first < a[i]) {
      swap(a[i], a[-it->second]);
      break;
    }
    st.erase(make_pair(a[i], -i));
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], (i == n-1) ? '\n' : ' ');
  return 0;
}