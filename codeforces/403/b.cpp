#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

string a[N][2];
int pil[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string fi, se;
    cin >> fi >> se;
    a[i][0] = fi.substr(0, 3);
    a[i][1] = fi.substr(0, 2) + se.substr(0, 1);
  }
  memset(pil, 0, sizeof pil);
  set< string > st;
  for (int i = 0; i < n; i++) {
    if (pil[i]) {
      continue;
    }
    bool found = 0;
    for (int j = i+1; j < n; j++) {
      if (a[i][0] == a[j][0]) {
        found = 1;
        break;
      }
    }
    if (found) {
      for (int j = i; j < n; j++) if (a[i][0] == a[j][0]) {
        pil[j] = 1;
        st.insert(a[j][1]);
      }
      st.insert(a[i][0]);
    }
  }
  while (!st.empty()) {
    auto it = st.begin();
    string now = *it;
    st.erase(it);
    for (int i = 0; i < n; i++) if (pil[i] == 0 && a[i][0] == now) {
      pil[i] = 1;
      st.insert(a[i][1]);
    }
  }
  bool ok = 1;
  for (int i = 0; i < n && ok; i++) {
    for (int j = i+1; j < n && ok; j++)
      if (a[i][pil[i]] == a[j][pil[j]])
        ok = 0;
  }
  if (ok) {
    puts("YES");
    for (int i = 0; i < n; i++)
      cout << a[i][pil[i]] << "\n";
  }
  else
    puts("NO");
  return 0;
}