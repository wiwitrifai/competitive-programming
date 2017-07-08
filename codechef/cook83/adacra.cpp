#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 55;
 
char s[N];
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int len = strlen(s), cnt = 1;
        for (int i = 0; i < len-1; i++) {
            cnt += s[i] != s[i+1];
        }
        printf("%d\n", cnt/2);
    }
    return 0;
} 