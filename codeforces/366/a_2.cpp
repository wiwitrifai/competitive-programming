#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    if(i & 1)
      printf("I love ");
    else
      printf("I hate ");
    if(i == n-1)
      printf("it\n");
    else
      printf("that ");
  }
  return 0;
}