#include <bits/stdc++.h>

using namespace std;


int get(int & a, int & b) {
  string buffer;
  getline(cin, buffer);
  a = b = 0;
  int id = 0;
  int ret = 0;
  if (ret < buffer.size())
    ret++; 
  while (id < buffer.size()) {
    if (buffer[id] > '9' || buffer[id] < '0')
      break;
    a *= 10;
    a += buffer[id]-'0';  
    id++;
  }
  while (id < buffer.size() && (buffer[id] < '0' || buffer[id] > '9')) id++; 
  if (id < buffer.size()) {
    ret++;
    while (id < buffer.size()) {
      if (buffer[id] > '9' || buffer[id] < '0')
        break;
      b *= 10;
      b += buffer[id] - '0';
      id++;
    }
  }
  return ret;
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  int ans = 0;
  int cnt = 0;
  int a, b, p, q, r;
  while (!(cnt = get(a, b)));
  while (cnt) {
    if (a > b)
      swap(a, b);
    p = a; q = b; r = 0;
    cnt = get(a, b);
    if (cnt == 1) {
      r = a;
      cnt = get(a, b);
    }
    if (q-p > x)
      ans += r;
    else
      ans += q;
  }
  printf("%d\n", ans);
  return 0;
}