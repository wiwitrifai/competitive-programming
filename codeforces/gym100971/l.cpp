#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], b[N], n;
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  for(int i = 0; i<n; i++)
    scanf("%d", b+i);
  sort(a, a+n);
  sort(b, b+n);
  bool first, second;
  int cnt = 0, last = 0;
  for(int i = 0; i<n; i++) if(a[i] > b[last]) {
    cnt++;
    last++;
  }
  first = (cnt > n-cnt);
  cnt = last = 0;
  for(int i = 0; i<n; i++) if(b[i] > a[last]) {
    cnt++;
    last++;
  }
  second = (cnt > n-cnt);
  if(first && second)
    puts("Both");
  else if(first)
    puts("First");
  else if(second)
    puts("Second");
  else
    puts("None");
  return 0;
}