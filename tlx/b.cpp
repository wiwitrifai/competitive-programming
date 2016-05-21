#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int b[10], a[10], id[10];

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", b+i);
    id[i] = i;
  }
  if(n == 5) {
    puts("0 1 2 3 4");
    return 0;
  }
  int now = 0;
  for(int i = 0; i<n; i++) {
    a[(now+5) % n] = b[(now + 1) % n] - b[now] + a[now];
    now += 5;
    now %= n;
  }
  // for(int i = 0; i<n; i++)
  //   cout << a[i] << endl;
  sort(id, id+n, [](int x, int y) {return a[x] < a[y];});
  for(int i = 0; i<5; i++)
    printf("%d ", id[i]);
  cout << endl;
  return 0;
} 