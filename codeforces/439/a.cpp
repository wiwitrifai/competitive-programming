#include <bits/stdc++.h>

using namespace std;

const int N = 2017;

int a[N], b[N], n;

int main() {
  set<int> st;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    st.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b+i);
    st.insert(b[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans += st.count(a[i] ^ b[j]);
  puts(ans & 1 ? "Koyomi" : "Karen");
  return 0;
}