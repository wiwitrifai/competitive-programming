// Sumber : http://e-maxx.ru/algo/palindromes_count 

vector<int> d1 (n);
int l=0, r=-1;
for (int i=0; i<n; ++i) {
  int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
  while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
  d1[i] = k--;
  if (i+k > r)
    l = i-k,  r = i+k;
}
vector<int> d2 (n);
l=0, r=-1;
for (int i=0; i<n; ++i) {
  int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
  while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])  ++k;
  d2[i] = --k;
  if (i+k-1 > r)
    l = i-k,  r = i+k-1;
}



// Sumber : http://codeforces.com/blog/entry/12143
vector< vector<int> > p(2, vector<int>(n,0)); //p[1][i] even, p[0][i] odd palindrom center i
for (int z=0, l=0, r=0; z < 2; z++, l=0, r=0)
  for (int i = 0; i < n; i++) {
     if (i < r) p[z][i] = min(r-i+!z, p[z][l+r-i+!z]);
     int L = i-p[z][i], R = i+p[z][i]-!z;
     while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) p[z][i]++, L--, R++;
     if(R > r) l = L,r = R;
  }