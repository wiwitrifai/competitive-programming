#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N];
long long hanoi[N];
int last[N];

int main() {
    hanoi[0] = 1;
    for(int i = 1; i<N; i++)
        hanoi[i] = hanoi[i-1] + hanoi[i-1] + 1;
    scanf("%s", s);
    int n = strlen(s);
    reverse(s, s+n);
    long long ans = 0;
    int cnt = 0, id = n;
    for(int i = n-1; i>=0; i--) {
        last[i] = id;
        if(s[i] == '1') {
            cnt++;
            id = i;
        }
    }
    for(int i = 0; i<n; i++) {
        if(s[i] != '1')
            continue;
        if(cnt & 1) {
            ans += hanoi[i];
            cnt--;
        }
        else {
            ans += hanoi[last[i]] - hanoi[i];
            s[last[i]] = '0';
            cnt -= 2;
        }
    }
    cout << ans << endl;
    return 0;
}
