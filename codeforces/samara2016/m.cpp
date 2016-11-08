#include <bits/stdc++.h>

using namespace std;

char response[10];

bool compare(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  scanf("%s", response);
  return (response[0] == '<');
}
vector< int > solve(int a, int b) {
  if (a == b) {
    vector<int> v;
    v.push_back(a);
    return v;
  }
  int mid = (a + b) / 2;
  vector< int > va = solve(a, mid), vb = solve(mid+1, b);
  if (compare(va[0], vb[0])) {
    vb.push_back(va[0]);
    return vb;
  }
  else {
    va.push_back(vb[0]);
    return va;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector< int > v = solve(1, n);
  int ans = v[1];
  for (int i = 2; i < v.size(); i++) {
    if (compare(ans, v[i]))
      ans = v[i];
  }
  printf("! %d\n", ans);
  fflush(stdout);
  return 0;
}