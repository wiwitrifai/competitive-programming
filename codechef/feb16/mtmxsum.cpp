#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int a[N], b[N], n, l[N];
long long aa[N], da[N], bb[N], db[N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    a[i] = a[i] + i + 1;
    aa[0] = (aa[0] + a[i]) % mod;
  }
  for(int i = 0; i<n; i++) {
    scanf("%d", b+i);
    b[i] = b[i] + i + 1;
    bb[0] = (bb[0] + b[i]) % mod;
  }
  stack< int > st;
  for(int i = 0; i<n; i++) {
    while(!st.empty()) {
      if(a[st.top()] <= a[i])
        st.pop();
      else
        break;
    }
    l[i] = (st.empty() ? 0 : st.top()+1);
    st.push(i);
  }
  while(!st.empty())
    st.pop();
  for(int i = n-1; i>=0; i--) {
    while(!st.empty()) {
      if(a[st.top()] < a[i])
        st.pop();
      else
        break;
    }
    int x = (st.empty() ? n : st.top());
    if(x < n) {
      da[x-i] += a[x]-a[i];
      da[x-i] %= mod;
      da[x-l[i]+1] += a[i] - a[x];
      da[x-l[i]+1] %= mod;
    }
    else {
      da[x-i] += -a[i];
      da[x-i] %= mod;
      da[x-l[i]+1] += a[i];
      da[x-l[i]+1] %= mod;
    }
    st.push(i);
  }
  while(!st.empty())
    st.pop();
  for(int i = 0; i<n; i++) {
    while(!st.empty()) {
      if(b[st.top()] <= b[i])
        st.pop();
      else
        break;
    }
    l[i] = (st.empty() ? 0 : st.top()+1);
    st.push(i);
  }
  while(!st.empty())
    st.pop();
  for(int i = n-1; i>=0; i--) {
    while(!st.empty()) {
      if(b[st.top()] < b[i])
        st.pop();
      else
        break;
    }
    int x = (st.empty() ? n : st.top());
    if(x < n) {
      db[x-i] += b[x]-b[i];
      db[x-i] %= mod;
      db[x-l[i]+1] += b[i] - b[x];
      db[x-l[i]+1] %= mod;
    }
    else {
      db[x-i] += -b[i];
      db[x-i] %= mod;
      db[x-l[i]+1] += b[i];
      db[x-l[i]+1] %= mod;
    }
    st.push(i);
  }
  for(int i = 0; i<n; i++) {
    da[i+1] = (da[i] + da[i+1]) % mod;
    db[i+1] = (db[i] + db[i+1]) % mod;
  }
  for(int i = 0; i<n; i++) {
    aa[i] = (aa[i] + da[i]) % mod;
    bb[i] = (bb[i] + db[i]) % mod;
    long long now = (aa[i]*bb[i]) % mod;
    if(now < 0)
      now += mod;
    printf("%lld%c", now, (i == n-1) ? '\n' : ' ');
    aa[i+1] += aa[i];
    aa[i+1] %= mod;
    bb[i+1] += bb[i];
    bb[i+1] %= mod;
  }
  return 0;
}