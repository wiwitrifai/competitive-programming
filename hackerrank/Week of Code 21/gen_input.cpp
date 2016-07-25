#include <bits/stdc++.h>

using namespace std;

int main() {
  set< pair<int, int > > st;
  int n;
  srand(time(NULL)); 
  scanf("%d", &n);
  printf("%d\n", n);
  while(st.size() < n) {
    int x = (rand() % 20001) - 10000, y = (rand() % 20001) - 10000;
    st.insert(make_pair(x, y));
  }
  for(auto it : st) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}