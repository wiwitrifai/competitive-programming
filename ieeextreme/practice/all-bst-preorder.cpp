   
#include <bits/stdc++.h>
using namespace std;

vector<int> val;
stack<pair<int, int>> st;
int N;
void bst(int id) {
  int l = st.top().first, r = st.top().second;
  st.pop();
  if (id+1 == N) {
    val[id] = l;
    for (int i = 0; i < N; i++)
      printf("%d%c", val[i], i+1 == N ? '\n' : ' ');
    st.push(make_pair(l, r));
    return;
  }
  for (int i = l; i <= r; i++) {
    val[id] = i;
    if (i < r)
      st.push(make_pair(i+1, r));
    if (l < i)
      st.push(make_pair(l, i-1));
    bst(id+1);
    if (i < r)
      st.pop();
    if (l < i)
      st.pop();
  }
  st.push(make_pair(l, r));
}
void allBstPreorders(int N) {
    ::N = N;
    val.resize(N);
    while (!st.empty())
    st.pop();
    st.push(make_pair(1, N));
    bst(0);
}
   
int main() {
    int N;
    cin >> N;
    allBstPreorders(N);
    return 0;
}