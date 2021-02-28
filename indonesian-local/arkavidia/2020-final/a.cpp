
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T,null_type,greater<T>,rb_tree_tag,tree_order_statistics_node_update> ;

int main() {
  ordered_set<pair<int, int>> st;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    st.insert(make_pair(a, st.size()));
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, a;
    scanf("%d %d", &t, &a);
    if (t == 1)
      st.insert(make_pair(a, st.size()));
    else
      printf("%d\n", st.find_by_order(a-1)->first);
  }
}
