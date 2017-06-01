#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;


int sa[N], pos[N], lcp[N], tmp[N], gap, n, add[N];
int p, q;
char s[N];

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}


void build_sa() {
  for(int i = 0; i<n; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + n, cmp_sa);
    for(int i = 1; i<n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<n; i++) pos[sa[i]] = tmp[i];
    if(tmp[n-1] == n-1) break;
  }
}

void build_lcp() {
  for(int i = 0, k = 0; i<n; i++) if(pos[i] - n + 1) {
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k]; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}



int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int a = strlen(s);
    scanf("%s", s+a+1);
    s[a] = ' ';
    int b = strlen(s+a+1);
    n = a + b+1;
    reverse(s+a+1, s+n);
    // cerr << s << endl;
    build_sa();
    // cerr << "build sa done" << endl;
    build_lcp();
    // cerr << "build lcp done" << endl;
    memset(add, 0, sizeof add);
    vector<vector<int>> p(2,vector<int>(n,0));
    for(int z=0,l=0,r=0;z<2;z++,l=0,r=0) {
      for(int i=0;i<a;i++)
      {
          if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
          int L=i-p[z][i], R=i+p[z][i]-!z;
          while(L-1>=0 && R+1<a && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
          if(R>r) l=L,r=R;
      }
      l = a+1; r = a+1;
      for(int i=a+1;i<n;i++)
      {
          if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
          int L=i-p[z][i], R=i+p[z][i]-!z;
          while(L-1>=a+1 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
          if(R>r) l=L,r=R;
      }
      set< pair<int, int> > st;
      for(int i= n-1; i>=0; i--) {
        while(!st.empty()) {
          auto it = --st.end();
          if(it->second > i+1)
            st.erase(it);
          else
            break;
        }
        if(!st.empty()) {
          auto it = --st.end();
          add[i] = max(add[i], 2*(it->first-i-1) + z);
        }
        st.insert({i, i-p[z][i]});
      } 
    }
    add[a-1] = 0;
    // for(int i = 0; i<n; i++) 
    //   cerr << i << " add " << add[i] << " " << s+sa[i] << " " << lcp[i] << endl;
    int ma = -1, mb = -1, la = -1, lb = -1;
    string ans = "";
    for(int i = 0; i<n; i++) {
      if(sa[i] < a) {
        if(mb > 0) {
          int ad = max(add[sa[i] + mb -1], add[sa[lb] + mb -1]);
          string tmp = "";
          if(ans.size() <= 2*mb + ad) {
            tmp.append(s+sa[i], mb);
            if(add[sa[i]+mb-1] < add[sa[lb]+mb-1])
              tmp.append(s + sa[lb]+mb, ad);
            else if(add[sa[i]+mb-1] > add[sa[lb]+mb-1])
              tmp.append(s + sa[i]+mb, ad);
            else if(strncmp(s+sa[i]+mb, s+sa[lb]+mb, ad) < 0)
              tmp.append(s + sa[i]+mb, ad);
            else
              tmp.append(s + sa[lb]+mb, ad);
            reverse(s+sa[i], s+sa[i]+mb);
            tmp.append(s+sa[i], mb);
            reverse(s+sa[i], s+sa[i]+mb);
            if((tmp.size() > ans.size()) || (tmp < ans))
              ans = tmp;
          }
        }
        ma = n;
        la = i;
      }
      else {
        if(ma > 0) {
          int ad = max(add[sa[i] + ma -1], add[sa[la] + ma -1]);
          string tmp = "";
          if(ans.size() <= 2*ma + ad) {
            tmp.append(s+sa[la], ma);
            if(add[sa[i]+ma-1] < add[sa[la]+ma-1])
              tmp.append(s + sa[la]+ma, ad);
            else if(add[sa[i]+ma-1] > add[sa[la]+ma-1])
              tmp.append(s + sa[i]+ma, ad);
            else if(strncmp(s+sa[i]+ma, s+sa[la]+ma, ad) < 0)
              tmp.append(s + sa[i]+ma, ad);
            else
              tmp.append(s + sa[la]+ma, ad);
            reverse(s+sa[i], s+sa[i]+ma);
            tmp.append(s+sa[i], ma);
            reverse(s+sa[i], s+sa[i]+ma);
            if((tmp.size() > ans.size()) || (tmp < ans))
              ans = tmp;
          }
        }
        mb = n;
        lb = i;
      }
      mb = min(mb, lcp[i]);
      ma = min(ma, lcp[i]);
    }
    ma = -1, mb = -1, la = -1, lb = -1;
    for(int i = n-1; i>=0; i--) {
      if(sa[i] < a) {
        if(mb > 0) {
          int ad = max(add[sa[i] + mb -1], add[sa[lb] + mb -1]);
          string tmp = "";
          if(ans.size() <= 2*mb + ad) {
            tmp.append(s+sa[i], mb);
            if(add[sa[i]+mb-1] < add[sa[lb]+mb-1])
              tmp.append(s + sa[lb]+mb, ad);
            else if(add[sa[i]+mb-1] > add[sa[lb]+mb-1])
              tmp.append(s + sa[i]+mb, ad);
            else if(strncmp(s+sa[i]+mb, s+sa[lb]+mb, ad) < 0)
              tmp.append(s + sa[i]+mb, ad);
            else
              tmp.append(s + sa[lb]+mb, ad);
            reverse(s+sa[i], s+sa[i]+mb);
            tmp.append(s+sa[i], mb);
            reverse(s+sa[i], s+sa[i]+mb);
            if((tmp.size() > ans.size()) || (tmp < ans))
              ans = tmp;
          }
        }
        ma = n;
        la = i;
      }
      else {
        if(ma > 0) {
          int ad = max(add[sa[i] + ma -1], add[sa[la] + ma -1]);
          string tmp = "";
          if(ans.size() <= 2*ma + ad) {
            tmp.append(s+sa[la], ma);
            if(add[sa[i]+ma-1] < add[sa[la]+ma-1])
              tmp.append(s + sa[la]+ma, ad);
            else if(add[sa[i]+ma-1] > add[sa[la]+ma-1])
              tmp.append(s + sa[i]+ma, ad);
            else if(strncmp(s+sa[i]+ma, s+sa[la]+ma, ad) < 0)
              tmp.append(s + sa[i]+ma, ad);
            else
              tmp.append(s + sa[la]+ma, ad);
            reverse(s+sa[i], s+sa[i]+ma);
            tmp.append(s+sa[i], ma);
            reverse(s+sa[i], s+sa[i]+ma);
            if((tmp.size() > ans.size()) || (tmp < ans))
              ans = tmp;
          }
        }
        mb = n;
        lb = i;
      }
      mb = min(mb, lcp[i-1]);
      ma = min(ma, lcp[i-1]);
    }
    // cerr << s << endl;
    // cerr << ans << " " << aa << " " << bb << " " << mm << " " << add[aa + mm -1] << endl;
    if(ans.size() == 0) {
      puts("-1");
      continue;
    }
    printf("%s\n", ans.c_str());
  }

  return 0;
}