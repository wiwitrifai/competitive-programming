#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
long double r[11];
char s[N];

long double solve() {
  int m = strlen(s);
  stack< pair< long double, int > > st;
  int i = 0;
  long double now = 0, bef;
  int op = -1, id;
  while(i < m) {
    switch(s[i]) {
      case '(':
        st.push({now, op});
        now = 0;
        op = -1;
        i++;
      break;
      case ')':
        bef = st.top().first;
        if(op == 0)
          now = 1/now;
        op = st.top().second;
        st.pop();
        if(op == 1)
          now += bef;
        else
          if(op == 0)
           now = 1/now + bef;
        i++;
        break;
      case '|':
        if(op == -1)
          now = 1/now;
        op = 0;
        i++;
        break;
      case '-':
        op = 1;
        i++;
        break;
      default:
        i++;
        id = s[i] - '1';
        if(op == 1)
          now += r[id];
        else if(op == 0)
          now += 1/r[id];
        else
          now = r[id];
        i++;
    }
  }
  if(op == 0)
    now = 1/now;
  return now;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    cin >> r[i];
  scanf("%s", s);
  cout << fixed << setprecision(20) << solve() << endl;
  return 0;
}