#include <cstdio>
#include <cassert>
#include "shortcut.h"

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
