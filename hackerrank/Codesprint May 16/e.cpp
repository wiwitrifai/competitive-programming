#include <bits/stdc++.h>

using namespace std;
void inc(char * arr, int id, int dd = 1) {
  arr[id]++;
  while(arr[id] > '9') {
    arr[id] -= 10;
    id+= dd;
    if(arr[id] > '9' || arr[id] < '0')
      arr[id] = '0';
    arr[id]++;
  }
}
void dec(char * arr, int id, int dd = 1) {
  arr[id]--;
  while(arr[id] < '0') {
    arr[id] += 10;
    id += dd;
    if(arr[id] > '9' || arr[id] < '0')
      arr[id] = '0';
    arr[id]--;
  }
}
void sub(char * arr1, char *arr2, int n, int m) {
  int sisa = 0;
  int j = m-1;
  for(int i = n-1; i>=0; i--, j--) {
    arr1[i] -= sisa + (j>=0 ? arr2[j]-'0' : 0);
    sisa = 0;
    while(arr1[i] < '0') {
      arr1[i] += 10;
      sisa++;
    }
  }
}
bool zero(char * arr) {
  int n = strlen(arr);
  for(int i = 0; i<n; i++)
    if(arr[i] != '0')
      return false;
    return true;
}
int add(char * a, char * b) {
  int n = strlen(a), m = strlen(b);
  int sisa = 0;
  for(int i = 0; i<max(n, m); i++) {
    if(i < n)
      sisa += a[i] - '0';
    if(i < m)
      sisa += b[i] - '0';
    a[i] = (sisa % 10) + '0';
    sisa /= 10;
  }
  while(sisa) {
    a[n++] = (sisa % 10) + '0';
    sisa /= 10; 
  }
  a[n] = '\0';
  return n;
}

const int N = 1e6 + 6;
char s[N], t[N];
int nans = 0, ntmp = 0;
char ans[50][N];
char tmp[50][N];
char ss[N];

int main() {
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t);
  reverse(s, s+n);
  reverse(t, t+m);
  if(n == m) {
    while(n > 0 && s[n-1] == t[n-1])
      n--;
    m = n;
    s[n] = t[m] = '\0';
  }
  // cerr << n << m << endl;
  ntmp = 1;
  tmp[0][0] = t[0];
  tmp[0][1] = '\0';
  if(n == m && n == 0) {
    puts("1");
    puts("0 1");
    return 0;
  }
  if(n == m && n == 1) {
    puts("1");
    printf("0 %d", t[0]-s[0]+1);
    return 0;
  }
  for(int i = 1; i<m; i += i, ntmp++) {
    int j = min(i+i-1, m-1);
    for(int k = 0; k<(j-i+1); k++)
      tmp[ntmp][k] = t[j-k];
    tmp[ntmp][j-i+1] = '\0';
  }
  dec(s, 0);
  nans = 1;
  ans[0][0] = s[0];
  ans[0][1] = '\0';
  for(int i = 1; i<n; i += i, nans++) {
    int j = min(i+i-1, n-1);
    for(int k = 0; k<(j-i+1); k++)
      ans[nans][k] = s[j-k];
    ans[nans][j-i+1] = '\0';
  }
  ntmp--; nans--;
  if(nans == ntmp) {
    sub(tmp[ntmp], ans[nans], strlen(tmp[ntmp]), strlen(ans[nans]));
    ans[nans][0] = '\0';
    assert(!zero(tmp[ntmp]));
  }
  else {
    for(int i= nans+1; i<=ntmp; i++)
      ans[i][0] = '\0';
  }
  dec(tmp[ntmp], strlen(tmp[ntmp])-1, -1);
  nans = ntmp-1;
  for(int i = 0; i<(1<<nans); i++)
    ss[i] = '0';
  n = min(n, 1<<nans);
  ss[1<<nans] = '1';
  ss[(1<<nans)+1] = '\0';
  reverse(ss, ss+(1<<nans)+1);
  reverse(s, s+n);
  sub(ss, s, (1<<nans)+1, n);
  reverse(ss, ss+(1<<nans)+1);
  n = (1<<nans)+1;
  while(n > 0 && ss[n-1] == '0') n--;
  nans = 1;
  if(n > 0)
    ans[0][0] = ss[0];
  else
    ans[0][0] = '\0';
  ans[0][1] = '\0';
  for(int i = 1; i<n; i += i, nans++) {
    int j = min(i+i-1, n-1);
    for(int k = 0; k<(j-i+1); k++)
      ans[nans][k] = ss[j-k];
    ans[nans][j-i+1] = '\0';
  }
  nans--;
  while(nans > 0 && zero(ans[nans])) nans--;
  while(ntmp > 0 && zero(tmp[ntmp])) ntmp--;
  if(nans == ntmp) {
    reverse(ans[nans], ans[nans] + strlen(ans[nans]));
    reverse(tmp[nans], tmp[nans] + strlen(tmp[nans]));
    int len = add(ans[nans], tmp[nans]);
    tmp[nans][0] = '\0';
    reverse(ans[nans], ans[nans]+len);
    ans[nans][len] = '\0';
  }
  int all = 0;
  for(int i = 0; i<=nans; i++)
    if(!zero(ans[i]))
      all++;
  for(int i = 0; i<=ntmp; i++)
    if(!zero(tmp[i]))
      all++;
  printf("%d\n", all);
  for(int i = 0; i<=nans; i++)
    if(!zero(ans[i])) {
      int off = 0;
      while(ans[i][off] == '0') off++;
      printf("%d %s\n", i, ans[i]+off);
    }
  for(int i = ntmp; i>=0; i--)
    if(!zero(tmp[i])) {
      int off = 0;
      while(tmp[i][off] == '0') off++;
      printf("%d %s\n", i, tmp[i]+off);
    }
  return 0;
}