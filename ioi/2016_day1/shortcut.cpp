#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > adj[N];
const long long inf = 1e18;
long long tmp[N];

long long find_shortcut(int n, std::vector<int> l, std::vector<int> d, int c)
{
  long long ans = inf;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      cerr << i << " - " << j << " " << ans << endl;
      long long now = 0;
      long long dist = 0;
      for (int k = i; k < j; k++)
        dist += l[k];
      long long suml = d[0];
      for (int k = 0; k < i; k++) {
        suml += l[k];
        suml = max(suml, (long long)d[k+1]);
      }
      long long sumr = d[n-1];
      for (int k = n-1; k > j; k--) {
        sumr += l[k-1];
        sumr = max(sumr, (long long)d[k-1]);
      }
      now = suml + min((long long)c, dist) + sumr;
      long long cur = 0;
      for (int k = i; k <= j; k++) {
        now = max(now, max(suml + d[k] + min(cur, dist+c-cur), sumr + d[k] + min(dist-cur, c + cur)));
        cerr << k << " " << d[k] + min(cur, dist+c-cur) << " " <<  sumr + d[k] + min(dist-cur, c + cur) << endl;
        if (k < j)
          cur += l[k];
      }
      int id = i;
      cur = 0;
      set < pair< long long, int > > st;
      dist += c;
      int tmp = l[j];
      l[j] = c;
      suml = 0;
      st.insert({d[i], i});
      for (int k = i; k <= j; k++) {
        cerr << suml + dist - cur - l[id] << " wew " << cur - suml + l[id] << endl;
        while (suml + dist - cur - l[id] >= cur - suml + l[id]) {
          cur += l[id];
          id++;
          if (id == j+1)
            id = i;
          cerr << id << " jaha " << cur + st.rbegin()->first + d[id] << endl;
          now = max(now, cur + st.rbegin()->first + d[id]);
          st.insert({d[id]-cur, id});
        }
        st.erase({d[k]-suml, k});
        suml += l[k];
      }
      l[j] = tmp;
      ans = min(ans, now);
    } 
  }
  return ans;
}

int main()
{
    int n, c;
    assert(2 == scanf("%d%d", &n, &c));
    
    std::vector<int> l(n - 1);
    std::vector<int> d(n);
    for (int i = 0; i < n - 1; i++)
        assert(1 == scanf("%d", &l[i]));
    for (int i = 0; i < n; i++)
        assert(1 == scanf("%d", &d[i]));
        
    long long t = find_shortcut(n, l, d, c);
    
    
    printf("%lld\n", t);
    
    return 0;
}

